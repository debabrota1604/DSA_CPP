#include <wmmintrin.h>
#include <cstdint>
#include <iostream>
#include <smmintrin.h>
#include <iomanip>  // Include this header for setw and setfill
#include "cpuProfiler.hpp"

class AesGcmObj{
    public:
    __m128i inputIV;
    __m128i encryptedIV;
    size_t encIV_unusedLen;
    __m128i key_schedule[15];

    AesGcmObj(){
        encIV_unusedLen =0;
    }

    // For single block encrypt using AES
	void encrypt(__m128i& plaintext, __m128i& ciphertext) noexcept{
        ciphertext = _mm_xor_si128(plaintext, key_schedule[0]);
        for(auto iter=1; iter<14; iter++){
            ciphertext = _mm_aesenc_si128(ciphertext, key_schedule[iter]);
        }
		ciphertext = _mm_aesenclast_si128(ciphertext, key_schedule[14]);
	}
};

class AES256GCM_NoTag_partialBlockFix{  
    AesGcmObj *encObj, *decObj;
    size_t precompute_xor_len;

    [[nodiscard]] static __m128i aes_expand_key_evn_step(__m128i key0, __m128i key1) noexcept
    {
        key0 = _mm_xor_si128(key0, _mm_slli_si128(key0, 4));
        key0 = _mm_xor_si128(key0, _mm_slli_si128(key0, 4));
        key0 = _mm_xor_si128(key0, _mm_slli_si128(key0, 4));
        return _mm_xor_si128(key0, _mm_shuffle_epi32(key1, 0xff));
    }

    [[nodiscard]] static __m128i aes_expand_key_odd_step(__m128i key0, __m128i key1) noexcept
    {
        key0 = _mm_aeskeygenassist_si128(key0, 0);
        key1 = _mm_xor_si128(key1, _mm_slli_si128(key1, 4));
        key1 = _mm_xor_si128(key1, _mm_slli_si128(key1, 4));
        key1 = _mm_xor_si128(key1, _mm_slli_si128(key1, 4));
        return _mm_xor_si128(key1, _mm_shuffle_epi32(key0, 0xaa));
    }  

    void load_key_256_encrypt(__m128i *key_schedule, const uint8_t key[32]) noexcept
	{
		key_schedule[0] = _mm_loadu_si128(&reinterpret_cast<const __m128i*>(key)[0]);
		key_schedule[1] = _mm_loadu_si128(&reinterpret_cast<const __m128i*>(key)[1]);
		key_schedule[2] = aes_expand_key_evn_step(key_schedule[0], _mm_aeskeygenassist_si128(key_schedule[1], 0x01));
		key_schedule[3] = aes_expand_key_odd_step(key_schedule[2], key_schedule[1]);
		key_schedule[4] = aes_expand_key_evn_step(key_schedule[2], _mm_aeskeygenassist_si128(key_schedule[3], 0x02));
		key_schedule[5] = aes_expand_key_odd_step(key_schedule[4], key_schedule[3]);
		key_schedule[6] = aes_expand_key_evn_step(key_schedule[4], _mm_aeskeygenassist_si128(key_schedule[5], 0x04));
		key_schedule[7] = aes_expand_key_odd_step(key_schedule[6], key_schedule[5]);
		key_schedule[8] = aes_expand_key_evn_step(key_schedule[6], _mm_aeskeygenassist_si128(key_schedule[7], 0x08));
		key_schedule[9] = aes_expand_key_odd_step(key_schedule[8], key_schedule[7]);
		key_schedule[10] = aes_expand_key_evn_step(key_schedule[8], _mm_aeskeygenassist_si128(key_schedule[9], 0x10));
		key_schedule[11] = aes_expand_key_odd_step(key_schedule[10], key_schedule[9]);
		key_schedule[12] = aes_expand_key_evn_step(key_schedule[10], _mm_aeskeygenassist_si128(key_schedule[11], 0x20));
		key_schedule[13] = aes_expand_key_odd_step(key_schedule[12], key_schedule[11]);
		key_schedule[14] = aes_expand_key_evn_step(key_schedule[12], _mm_aeskeygenassist_si128(key_schedule[13], 0x40));
	}
	
	
    void load_key_256_decrypt(__m128i *key_schedule, const uint8_t key[32]) noexcept
	{
        __m128i temp_keySchdule[15];
        load_key_256_encrypt(temp_keySchdule, key);

		key_schedule[14] = temp_keySchdule[0];
		key_schedule[13] = _mm_aesimc_si128(temp_keySchdule[1]);
		key_schedule[12] = _mm_aesimc_si128(temp_keySchdule[2]);
		key_schedule[11] = _mm_aesimc_si128(temp_keySchdule[3]);
		key_schedule[10] = _mm_aesimc_si128(temp_keySchdule[4]);
		key_schedule[9] = _mm_aesimc_si128(temp_keySchdule[5]);
		key_schedule[8] = _mm_aesimc_si128(temp_keySchdule[6]);
		key_schedule[7] = _mm_aesimc_si128(temp_keySchdule[7]);
		key_schedule[6] = _mm_aesimc_si128(temp_keySchdule[8]);
		key_schedule[5] = _mm_aesimc_si128(temp_keySchdule[9]);
		key_schedule[4] = _mm_aesimc_si128(temp_keySchdule[10]);
		key_schedule[3] = _mm_aesimc_si128(temp_keySchdule[11]);
		key_schedule[2] = _mm_aesimc_si128(temp_keySchdule[12]);
		key_schedule[1] = _mm_aesimc_si128(temp_keySchdule[13]);
		key_schedule[0] = temp_keySchdule[14];
	}

    // Expand the IV to a 128-bit block
    __inline__ void load_iv96(__m128i& storage, uint8_t* iv_96b) { //reduces intermediate variable
        // Load the original 96-bit IV directly into the first 128-bit block, avoiding an extra register and store operation
        _mm_storeu_si128(&storage, _mm_loadu_si128((__m128i*)iv_96b));

        // Combine zeroing and setting the last byte in a single instruction, then bitwise-OR
        storage = _mm_insert_epi8(storage, 0x01, 15);
    }    
    
    // Load 128bit IV to a 128-bit block
    __inline__ void load_iv128(__m128i& storage, uint8_t* iv_128b) { //reduces intermediate variable
        // Load the original 96-bit IV directly into the first 128-bit block, avoiding an extra register and store operation
        _mm_storeu_si128(&storage, _mm_loadu_si128((__m128i*)iv_128b));

        // Combine zeroing and setting the last byte in a single instruction, then bitwise-OR
        storage = _mm_insert_epi8(storage, 0x01, 15);
    }

    __inline__ void inc32(__m128i& memory128b){
        static const __m128i SWAP_MASK = _mm_setr_epi8(0,1,2,3,4,5,6,7,8,9,10,11,15,14,13,12);
        memory128b = _mm_shuffle_epi8(_mm_add_epi32(_mm_shuffle_epi8(memory128b, SWAP_MASK), _mm_setr_epi32(0,0,0,1)), SWAP_MASK); 
    }

    public:
    AES256GCM_NoTag_partialBlockFix(){
    }
    ~AES256GCM_NoTag_partialBlockFix(){
    }
    void encrypt_aes256gcm_init(const uint8_t* key_encryption,  uint8_t* iv_encryption){
        encObj = new AesGcmObj();
        load_iv96(encObj->inputIV, iv_encryption);
        load_key_256_encrypt(&(*encObj->key_schedule), key_encryption);
    }
    void decrypt_aes256gcm_init(const uint8_t* key_decryption,  uint8_t* iv_decryption){
        decObj = new AesGcmObj();
        load_iv96(decObj->inputIV, iv_decryption);
        load_key_256_encrypt(&(*decObj->key_schedule), key_decryption);
    }

    void aes_gcm_process_blocks(const uint8_t* input, size_t len, uint8_t* output, AesGcmObj* obj) {
        precompute_xor_len = std::min(obj->encIV_unusedLen, len);
        const uint8_t* buffer = reinterpret_cast<const uint8_t*>(&obj->encryptedIV);

        //XOR initial bytes with precomputed values
        std::transform(input, input + precompute_xor_len, buffer + (16 - obj->encIV_unusedLen),
                    output, [](uint8_t a, uint8_t b) { return a ^ b; });

        // Update unused length
        obj->encIV_unusedLen = (16 + precompute_xor_len - len) % 16;

        // Process remaining blocks
        for (size_t i = precompute_xor_len; i < len; i += 16) {
            inc32(obj->inputIV);

            // Encrypt counter block
            obj->encrypt(obj->inputIV, obj->encryptedIV);

            // Process input and store output
            _mm_storeu_si128(reinterpret_cast<__m128i*>(output + i), _mm_aesenc_si128(_mm_loadu_si128(reinterpret_cast<const __m128i*>(input + i)), obj->encryptedIV));
        }
    }

    void aes_gcm_encrypt_partialBlockFix(uint8_t* plaintext, size_t plaintext_len, uint8_t* ciphertext) {
        aes_gcm_process_blocks(plaintext, plaintext_len, ciphertext, encObj);
    }

    void aes_gcm_decrypt_partialBlockFix(uint8_t* ciphertext, size_t ciphertext_len, uint8_t* plaintext) {
        aes_gcm_process_blocks(ciphertext, ciphertext_len, plaintext, decObj);
    }
};
/*   Optimized intel encrypt code, but not fixed for partial block inputs */
class AES256_GCM_NoTag{    
    public:
    // Stores all round keys
    __m128i key_schedule[15], key_schedule_decrypt[15];

    // Expand the IV to a 128-bit block
    __m128i *counter_block_enc, *counter_block_dec;

    AES256_GCM_NoTag(){
        this->counter_block_enc = nullptr;
        this->counter_block_dec = nullptr;
    }
    ~AES256_GCM_NoTag(){
        // Free the allocated memory
        if (this->counter_block_enc) _mm_free(this->counter_block_enc);
        if (this->counter_block_dec) _mm_free(this->counter_block_dec);
    }

    void initialize(const uint8_t* key,  uint8_t* iv){
        load_key_256_encrypt(key_schedule, key);
        load_key_256_decrypt(key_schedule_decrypt, key);
        load_iv_96(iv);
    }

    [[nodiscard]] static __m128i aes_expand_key_evn_step(__m128i key0, __m128i key1) noexcept
    {
        key0 = _mm_xor_si128(key0, _mm_slli_si128(key0, 4));
        key0 = _mm_xor_si128(key0, _mm_slli_si128(key0, 4));
        key0 = _mm_xor_si128(key0, _mm_slli_si128(key0, 4));
        return _mm_xor_si128(key0, _mm_shuffle_epi32(key1, 0xff));
    }

    [[nodiscard]] static __m128i aes_expand_key_odd_step(__m128i key0, __m128i key1) noexcept
    {
        key0 = _mm_aeskeygenassist_si128(key0, 0);
        key1 = _mm_xor_si128(key1, _mm_slli_si128(key1, 4));
        key1 = _mm_xor_si128(key1, _mm_slli_si128(key1, 4));
        key1 = _mm_xor_si128(key1, _mm_slli_si128(key1, 4));
        return _mm_xor_si128(key1, _mm_shuffle_epi32(key0, 0xaa));
    }    
    void load_key_256_encrypt(__m128i* key_schedule, const uint8_t key[32]) noexcept
	{
		key_schedule[0] = _mm_loadu_si128(&reinterpret_cast<const __m128i*>(key)[0]);
		key_schedule[1] = _mm_loadu_si128(&reinterpret_cast<const __m128i*>(key)[1]);
		key_schedule[2] = aes_expand_key_evn_step(key_schedule[0], _mm_aeskeygenassist_si128(key_schedule[1], 0x01));
		key_schedule[3] = aes_expand_key_odd_step(key_schedule[2], key_schedule[1]);
		key_schedule[4] = aes_expand_key_evn_step(key_schedule[2], _mm_aeskeygenassist_si128(key_schedule[3], 0x02));
		key_schedule[5] = aes_expand_key_odd_step(key_schedule[4], key_schedule[3]);
		key_schedule[6] = aes_expand_key_evn_step(key_schedule[4], _mm_aeskeygenassist_si128(key_schedule[5], 0x04));
		key_schedule[7] = aes_expand_key_odd_step(key_schedule[6], key_schedule[5]);
		key_schedule[8] = aes_expand_key_evn_step(key_schedule[6], _mm_aeskeygenassist_si128(key_schedule[7], 0x08));
		key_schedule[9] = aes_expand_key_odd_step(key_schedule[8], key_schedule[7]);
		key_schedule[10] = aes_expand_key_evn_step(key_schedule[8], _mm_aeskeygenassist_si128(key_schedule[9], 0x10));
		key_schedule[11] = aes_expand_key_odd_step(key_schedule[10], key_schedule[9]);
		key_schedule[12] = aes_expand_key_evn_step(key_schedule[10], _mm_aeskeygenassist_si128(key_schedule[11], 0x20));
		key_schedule[13] = aes_expand_key_odd_step(key_schedule[12], key_schedule[11]);
		key_schedule[14] = aes_expand_key_evn_step(key_schedule[12], _mm_aeskeygenassist_si128(key_schedule[13], 0x40));
	}
    void load_key_256_decrypt(__m128i* key_schedule, const uint8_t key[32]) noexcept
	{

		this->key_schedule_decrypt[14] = key_schedule[0];
		this->key_schedule_decrypt[13] = _mm_aesimc_si128(key_schedule[1]);
		this->key_schedule_decrypt[12] = _mm_aesimc_si128(key_schedule[2]);
		this->key_schedule_decrypt[11] = _mm_aesimc_si128(key_schedule[3]);
		this->key_schedule_decrypt[10] = _mm_aesimc_si128(key_schedule[4]);
		this->key_schedule_decrypt[9] = _mm_aesimc_si128(key_schedule[5]);
		this->key_schedule_decrypt[8] = _mm_aesimc_si128(key_schedule[6]);
		this->key_schedule_decrypt[7] = _mm_aesimc_si128(key_schedule[7]);
		this->key_schedule_decrypt[6] = _mm_aesimc_si128(key_schedule[8]);
		this->key_schedule_decrypt[5] = _mm_aesimc_si128(key_schedule[9]);
		this->key_schedule_decrypt[4] = _mm_aesimc_si128(key_schedule[10]);
		this->key_schedule_decrypt[3] = _mm_aesimc_si128(key_schedule[11]);
		this->key_schedule_decrypt[2] = _mm_aesimc_si128(key_schedule[12]);
		this->key_schedule_decrypt[1] = _mm_aesimc_si128(key_schedule[13]);
		this->key_schedule_decrypt[0] = key_schedule[14];
	}

    void load_iv_96(uint8_t* iv_96b) { //reduces intermediate variable
        counter_block_enc = (__m128i*)_mm_malloc(sizeof(__m128i), 16);
        counter_block_dec = (__m128i*)_mm_malloc(sizeof(__m128i), 16);
        // Load the original 96-bit IV directly into the first 128-bit block,
        // avoiding an extra register and store operation
        _mm_storeu_si128(this->counter_block_enc, _mm_loadu_si128((__m128i*)iv_96b));

        // Combine zeroing and setting the last byte in a single instruction, then bitwise-OR
        *counter_block_enc = _mm_insert_epi8(*counter_block_enc, 0x01, 15);
        *counter_block_dec = *counter_block_enc;
    }

    void aes_gcm_encrypt(uint8_t* plaintext, size_t plaintext_len, uint8_t* ciphertext) {
        // Encrypt plaintext blocks
        for (size_t i = 0; i < plaintext_len; i += 16) {
            __m128i encrypted_counter_block;
            inc32_minimal(counter_block_enc);
            encrypt_iv(counter_block_enc, &encrypted_counter_block);

            // XOR plaintext with the encrypted counter block
            __m128i input_block = _mm_loadu_si128(reinterpret_cast<__m128i*>(plaintext + i));
            __m128i ciphertext_block = _mm_xor_si128(input_block, encrypted_counter_block);
            _mm_storeu_si128((__m128i*)(ciphertext + i), ciphertext_block);
        }
    }
    void aes_gcm_decrypt(uint8_t* ciphertext, size_t ciphertext_len, uint8_t* plaintext) {
        // Decrypt ciphertext blocks
        for (size_t i = 0; i < ciphertext_len; i += 16) {
            __m128i encrypted_counter_block;
            inc32_minimal(counter_block_dec);
            encrypt_iv(counter_block_dec, &encrypted_counter_block); 

            // XOR ciphertext with the encrypted counter block to obtain the plaintext
            __m128i ciphertext_block = _mm_loadu_si128(reinterpret_cast<__m128i*>(ciphertext + i));
            __m128i plaintext_block = _mm_xor_si128(ciphertext_block, encrypted_counter_block);
            _mm_storeu_si128((__m128i*)(plaintext + i), plaintext_block);
        }
    }

    void inc32_minimal(__m128i* memory128b){
        __m128i SWAP_MASK = _mm_setr_epi8(0,1,2,3,4,5,6,7,8,9,10,11,15,14,13,12);
        *memory128b = _mm_shuffle_epi8(_mm_add_epi32(_mm_shuffle_epi8(*memory128b, SWAP_MASK), _mm_setr_epi32(0,0,0,1)), SWAP_MASK); 
    }

    // For single block encrypt using AES
	void encrypt_iv(const __m128i* plaintext, __m128i* ciphertext) noexcept
	{
        *ciphertext = _mm_xor_si128(*plaintext, key_schedule[0]);
        for(auto iter=1; iter<14; iter++){
            *ciphertext = _mm_aesenc_si128(*ciphertext, key_schedule[iter]);
        }
		*ciphertext = _mm_aesenclast_si128(*ciphertext, key_schedule[14]);
	}
};

/*   Optimized intel encrypt code, but not fixed for partial block inputs */
class AES256GCM_bugOpt{    
    public:
    // Stores all round keys
    __m128i key_schedule[15], key_schedule_decrypt[15];

    // Expand the IV to a 128-bit block
    __m128i *counter_block_enc, *counter_block_dec;
    AesGcmObj *encObj, *decObj;

    AES256GCM_bugOpt(){
        this->counter_block_enc = (__m128i*)_mm_malloc(sizeof(__m128i), 16);
        this->counter_block_dec = (__m128i*)_mm_malloc(sizeof(__m128i), 16);
    }
    ~AES256GCM_bugOpt(){
        // Free the allocated memory
        if (this->counter_block_enc) _mm_free(this->counter_block_enc);
        if (this->counter_block_dec) _mm_free(this->counter_block_dec);
    }

    void initialize(const uint8_t* key,  uint8_t* iv){
        // load_key_256_encrypt(key_schedule, key);
        // load_key_256_decrypt(key_schedule_decrypt, key);
        // load_iv_96(this->counter_block_enc, iv);
        // load_iv_96(this->counter_block_dec, iv);
        encrypt_aes256gcm_init(key, iv);
        decrypt_aes256gcm_init(key, iv);
    }

    void encrypt_aes256gcm_init(const uint8_t* key_encryption,  uint8_t* iv_encryption){
        encObj = new AesGcmObj();
        load_iv_96(&(encObj->inputIV), iv_encryption);
        load_key_256_encrypt(&(*encObj->key_schedule), key_encryption);
    }
    void decrypt_aes256gcm_init(const uint8_t* key_decryption,  uint8_t* iv_decryption){
        decObj = new AesGcmObj();
        load_iv_96(&(decObj->inputIV), iv_decryption);
        load_key_256_encrypt(&(*decObj->key_schedule), key_decryption);
    }

    [[nodiscard]] static __m128i aes_expand_key_evn_step(__m128i key0, __m128i key1) noexcept
    {
        key0 = _mm_xor_si128(key0, _mm_slli_si128(key0, 4));
        key0 = _mm_xor_si128(key0, _mm_slli_si128(key0, 4));
        key0 = _mm_xor_si128(key0, _mm_slli_si128(key0, 4));
        return _mm_xor_si128(key0, _mm_shuffle_epi32(key1, 0xff));
    }
    [[nodiscard]] static __m128i aes_expand_key_odd_step(__m128i key0, __m128i key1) noexcept
    {
        key0 = _mm_aeskeygenassist_si128(key0, 0);
        key1 = _mm_xor_si128(key1, _mm_slli_si128(key1, 4));
        key1 = _mm_xor_si128(key1, _mm_slli_si128(key1, 4));
        key1 = _mm_xor_si128(key1, _mm_slli_si128(key1, 4));
        return _mm_xor_si128(key1, _mm_shuffle_epi32(key0, 0xaa));
    }    
    void load_key_256_encrypt(__m128i* key_schedule, const uint8_t key[32]) noexcept
	{
		key_schedule[0] = _mm_loadu_si128(&reinterpret_cast<const __m128i*>(key)[0]);
		key_schedule[1] = _mm_loadu_si128(&reinterpret_cast<const __m128i*>(key)[1]);
		key_schedule[2] = aes_expand_key_evn_step(key_schedule[0], _mm_aeskeygenassist_si128(key_schedule[1], 0x01));
		key_schedule[3] = aes_expand_key_odd_step(key_schedule[2], key_schedule[1]);
		key_schedule[4] = aes_expand_key_evn_step(key_schedule[2], _mm_aeskeygenassist_si128(key_schedule[3], 0x02));
		key_schedule[5] = aes_expand_key_odd_step(key_schedule[4], key_schedule[3]);
		key_schedule[6] = aes_expand_key_evn_step(key_schedule[4], _mm_aeskeygenassist_si128(key_schedule[5], 0x04));
		key_schedule[7] = aes_expand_key_odd_step(key_schedule[6], key_schedule[5]);
		key_schedule[8] = aes_expand_key_evn_step(key_schedule[6], _mm_aeskeygenassist_si128(key_schedule[7], 0x08));
		key_schedule[9] = aes_expand_key_odd_step(key_schedule[8], key_schedule[7]);
		key_schedule[10] = aes_expand_key_evn_step(key_schedule[8], _mm_aeskeygenassist_si128(key_schedule[9], 0x10));
		key_schedule[11] = aes_expand_key_odd_step(key_schedule[10], key_schedule[9]);
		key_schedule[12] = aes_expand_key_evn_step(key_schedule[10], _mm_aeskeygenassist_si128(key_schedule[11], 0x20));
		key_schedule[13] = aes_expand_key_odd_step(key_schedule[12], key_schedule[11]);
		key_schedule[14] = aes_expand_key_evn_step(key_schedule[12], _mm_aeskeygenassist_si128(key_schedule[13], 0x40));
	}
    void load_key_256_decrypt(__m128i* key_schedule, const uint8_t key[32]) noexcept
	{

		this->key_schedule_decrypt[14] = key_schedule[0];
		this->key_schedule_decrypt[13] = _mm_aesimc_si128(key_schedule[1]);
		this->key_schedule_decrypt[12] = _mm_aesimc_si128(key_schedule[2]);
		this->key_schedule_decrypt[11] = _mm_aesimc_si128(key_schedule[3]);
		this->key_schedule_decrypt[10] = _mm_aesimc_si128(key_schedule[4]);
		this->key_schedule_decrypt[9] = _mm_aesimc_si128(key_schedule[5]);
		this->key_schedule_decrypt[8] = _mm_aesimc_si128(key_schedule[6]);
		this->key_schedule_decrypt[7] = _mm_aesimc_si128(key_schedule[7]);
		this->key_schedule_decrypt[6] = _mm_aesimc_si128(key_schedule[8]);
		this->key_schedule_decrypt[5] = _mm_aesimc_si128(key_schedule[9]);
		this->key_schedule_decrypt[4] = _mm_aesimc_si128(key_schedule[10]);
		this->key_schedule_decrypt[3] = _mm_aesimc_si128(key_schedule[11]);
		this->key_schedule_decrypt[2] = _mm_aesimc_si128(key_schedule[12]);
		this->key_schedule_decrypt[1] = _mm_aesimc_si128(key_schedule[13]);
		this->key_schedule_decrypt[0] = key_schedule[14];
	}

    void load_iv_96(__m128i* storage, uint8_t* iv_96b) { //reduces intermediate variable
        // Load the original 96-bit IV directly into the first 128-bit block,
        // avoiding an extra register and store operation
        _mm_storeu_si128(storage, _mm_loadu_si128((__m128i*)iv_96b));

        // Combine zeroing and setting the last byte in a single instruction, then bitwise-OR
        *storage = _mm_insert_epi8(*storage, 0x01, 15);
    }

    void aes_gcm_encrypt(uint8_t* plaintext, size_t plaintext_len, uint8_t* ciphertext) {
        // Encrypt plaintext blocks
        for (size_t i = 0; i < plaintext_len; i += 16) {
            __m128i encrypted_counter_block;
            inc32_minimal(counter_block_enc);
            encrypt_iv(counter_block_enc, &encrypted_counter_block);

            // XOR plaintext with the encrypted counter block
            __m128i input_block = _mm_loadu_si128(reinterpret_cast<__m128i*>(plaintext + i));
            __m128i ciphertext_block = _mm_xor_si128(input_block, encrypted_counter_block);
            _mm_storeu_si128((__m128i*)(ciphertext + i), ciphertext_block);
        }
    }
    void aes_gcm_decrypt(uint8_t* ciphertext, size_t ciphertext_len, uint8_t* plaintext) {
        // Decrypt ciphertext blocks
        for (size_t i = 0; i < ciphertext_len; i += 16) {
            __m128i encrypted_counter_block;
            inc32_minimal(counter_block_dec);
            encrypt_iv(counter_block_dec, &encrypted_counter_block); 

            // XOR ciphertext with the encrypted counter block to obtain the plaintext
            __m128i ciphertext_block = _mm_loadu_si128(reinterpret_cast<__m128i*>(ciphertext + i));
            __m128i plaintext_block = _mm_xor_si128(ciphertext_block, encrypted_counter_block);
            _mm_storeu_si128((__m128i*)(plaintext + i), plaintext_block);
        }
    }

    void inc32_minimal(__m128i* memory128b){
        __m128i SWAP_MASK = _mm_setr_epi8(0,1,2,3,4,5,6,7,8,9,10,11,15,14,13,12);
        *memory128b = _mm_shuffle_epi8(_mm_add_epi32(_mm_shuffle_epi8(*memory128b, SWAP_MASK), _mm_setr_epi32(0,0,0,1)), SWAP_MASK); 
    }

    // For single block encrypt using AES
	void encrypt_iv(const __m128i* plaintext, __m128i* ciphertext) noexcept
	{
        *ciphertext = _mm_xor_si128(*plaintext, key_schedule[0]);
        for(auto iter=1; iter<14; iter++){
            *ciphertext = _mm_aesenc_si128(*ciphertext, key_schedule[iter]);
        }
		*ciphertext = _mm_aesenclast_si128(*ciphertext, key_schedule[14]);
	}
};