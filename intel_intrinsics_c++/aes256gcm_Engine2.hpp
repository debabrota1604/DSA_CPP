#include <wmmintrin.h>
#include <cstdint>
#include <iostream>
#include <smmintrin.h>
#include <iomanip>  // Include this header for setw and setfill
#include "cpuProfiler.hpp"

/*   Optimized intel encrypt code, but not fixed for partial block inputs */
class AES256GCM_bugOpt{    
    public:
    // Stores all round keys
    __m128i key_schedule[15], key_schedule_decrypt[15];

    // Expand the IV to a 128-bit block
    __m128i counter_block_enc, counter_block_dec;
    __m128i encrypted_counter_block_enc, encrypted_counter_block_dec;


    // Stores remaining encrypted iv bytes left for future plaintexts
    size_t encIV_unusedLen, encIV_unusedLen_dec;


    AES256GCM_bugOpt(){
    }
    ~AES256GCM_bugOpt(){
    }

    void initialize(const uint8_t* key,  uint8_t* iv){
        encrypt_aes256gcm_init(key, iv);
        decrypt_aes256gcm_init(key, iv);

        //print_all_keys();
    }

    void encrypt_aes256gcm_init(const uint8_t* key_encryption,  uint8_t* iv_encryption){
        load_iv_96(&counter_block_enc, iv_encryption);
        load_key_256_encrypt(key_schedule, key_encryption);
        encIV_unusedLen =0;
    }
    void decrypt_aes256gcm_init(const uint8_t* key_decryption,  uint8_t* iv_decryption){
        load_iv_96(&counter_block_dec, iv_decryption);
        load_key_256_encrypt(key_schedule_decrypt, key_decryption);
        encIV_unusedLen_dec=0;
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

    // Not used as aes-gcm uses only encryption for iv. this is for backtesting purposes
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

    // Load 128bit IV to a 128-bit block
    __inline__ void load_iv128(__m128i* storage, uint8_t* iv_128b) { //reduces intermediate variable
        // Load the original 96-bit IV directly into the first 128-bit block, avoiding an extra register and store operation
        _mm_storeu_si128(storage, _mm_loadu_si128((__m128i*)iv_128b));

        // Combine zeroing and setting the last byte in a single instruction, then bitwise-OR
        *storage = _mm_insert_epi8(*storage, 0x01, 15);
    }

    void aes_gcm_encrypt_old(uint8_t* plaintext, size_t plaintext_len, uint8_t* ciphertext) {
        // Encrypt plaintext blocks
        for (size_t i = 0; i < plaintext_len; i += 16) {
            inc32_minimal(&counter_block_enc);
            encrypt_iv(&counter_block_enc, &encrypted_counter_block_enc, key_schedule);
            //encrypt_iv(&(encObj->inputIV), &(encObj->encryptedIV));

            // XOR plaintext with the encrypted counter block
            _mm_storeu_si128((__m128i*)(ciphertext + i), _mm_xor_si128(_mm_loadu_si128(reinterpret_cast<__m128i*>(plaintext + i)), encrypted_counter_block_enc));
        }
    }
    void aes_gcm_decrypt_old(uint8_t* ciphertext, size_t ciphertext_len, uint8_t* plaintext) {
        // Decrypt ciphertext blocks
        for (size_t i = 0; i < ciphertext_len; i += 16) {
            inc32_minimal(&counter_block_dec);
            encrypt_iv(&counter_block_dec, &encrypted_counter_block_dec, key_schedule_decrypt); 

            // XOR ciphertext with the encrypted counter block to obtain the plaintext
            _mm_storeu_si128((__m128i*)(plaintext + i), _mm_xor_si128(_mm_loadu_si128(reinterpret_cast<__m128i*>(ciphertext + i)), encrypted_counter_block_dec));
        }
    }

    void inc32_minimal(__m128i* memory128b){
        __m128i SWAP_MASK = _mm_setr_epi8(0,1,2,3,4,5,6,7,8,9,10,11,15,14,13,12);
        *memory128b = _mm_shuffle_epi8(_mm_add_epi32(_mm_shuffle_epi8(*memory128b, SWAP_MASK), _mm_setr_epi32(0,0,0,1)), SWAP_MASK); 
    }

    // For single block encrypt using AES
	void encrypt_iv(const __m128i* plaintext, __m128i* ciphertext, __m128i* key) noexcept
	{
        *ciphertext = _mm_xor_si128(*plaintext, key[0]);
        for(auto iter=1; iter<14; iter++){
            *ciphertext = _mm_aesenc_si128(*ciphertext, key[iter]);
        }
		*ciphertext = _mm_aesenclast_si128(*ciphertext, key[14]);
	}

    void aes_gcm_encrypt( uint8_t* input, size_t len, uint8_t* output) {
        const size_t precompute_xor_len = std::min(encIV_unusedLen, len);
        const uint8_t* buffer = reinterpret_cast<const uint8_t*>(&encrypted_counter_block_enc);

        //XOR initial bytes with precomputed values
        std::transform(input, input + precompute_xor_len, buffer + (16 - encIV_unusedLen),
                    output, [](uint8_t a, uint8_t b) { return a ^ b; });

        // Update unused length
        encIV_unusedLen = (16 + precompute_xor_len - len) % 16;

        // Process remaining blocks
        for (size_t i = precompute_xor_len; i < len; i += 16) {
            inc32_minimal(&counter_block_enc);
            // DEBUG_PRINT("Enc-Incremented IV: ", counter_block_enc);

            // Encrypt counter block
            encrypt_iv(&counter_block_enc, &encrypted_counter_block_enc, key_schedule); 
            // DEBUG_PRINT("Enc-Encrypted IV: ", encrypted_counter_block_enc);

            // Process input and store output
            //_mm_storeu_si128(reinterpret_cast<__m128i*>(output + i), _mm_aesenc_si128(_mm_loadu_si128(reinterpret_cast<const __m128i*>(input + i)), encrypted_counter_block_enc));
            // XOR ciphertext with the encrypted counter block to obtain the plaintext
            __m128i ciphertext_block = _mm_loadu_si128(reinterpret_cast<__m128i*>(input + i));
            __m128i plaintext_block = _mm_xor_si128(ciphertext_block, encrypted_counter_block_enc);
            _mm_storeu_si128((__m128i*)(output + i), plaintext_block);
        }
    }
    
    void aes_gcm_decrypt( uint8_t* input, size_t len, uint8_t* output) {
        const size_t precompute_xor_len = std::min(encIV_unusedLen_dec, len);
        const uint8_t* buffer = reinterpret_cast<const uint8_t*>(&encrypted_counter_block_dec);

        //XOR initial bytes with precomputed values
        std::transform(input, input + precompute_xor_len, buffer + (16 - encIV_unusedLen_dec),
                    output, [](uint8_t a, uint8_t b) { return a ^ b; });

        // Update unused length
        encIV_unusedLen_dec = (16 + precompute_xor_len - len) % 16;

        // Process remaining blocks
        for (size_t i = precompute_xor_len; i < len; i += 16) {
            inc32_minimal(&counter_block_dec);
            // DEBUG_PRINT("Dec-Incremented IV: ", counter_block_dec);

            // Encrypt counter block
            encrypt_iv(&counter_block_dec, &encrypted_counter_block_dec, key_schedule_decrypt); 
            // DEBUG_PRINT("Dec-Encrypted IV: ", encrypted_counter_block_dec);

            // Process input and store output
            //_mm_storeu_si128(reinterpret_cast<__m128i*>(output + i), _mm_aesenc_si128(_mm_loadu_si128(reinterpret_cast<const __m128i*>(input + i)), encrypted_counter_block_dec));
            // XOR ciphertext with the encrypted counter block to obtain the plaintext
            __m128i ciphertext_block = _mm_loadu_si128(reinterpret_cast<__m128i*>(input + i));
            __m128i plaintext_block = _mm_xor_si128(ciphertext_block, encrypted_counter_block_dec);
        }
    }

    void DEBUG_PRINT(std::string title, __m128i value) {
        uint8_t bytes[16];
        _mm_storeu_si128((__m128i*)bytes, value);

        std::cout << title << ": ";

        for (int i = 0; i < 16; ++i) {
            std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(bytes[i]) << " ";
        }
        std::cout << std::endl << std::endl;
    }

    void print_all_keys(){
        for(int iter=0; iter<15; iter++){
            std::string temp = "Round Key " + std::to_string(iter);
            print_aes_block(temp, this->key_schedule[iter]);
        }
    }

    void print_aes_block(std::string title, __m128i value) {
        uint8_t bytes[16];
        _mm_storeu_si128((__m128i*)bytes, value);

        std::cout << title << std::endl;

        for (int j = 0; j < 4; ++j) {
            for (int i = 0; i < 4; ++i) {
                int index = i * 4 + j;
                std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(bytes[index]) << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
};