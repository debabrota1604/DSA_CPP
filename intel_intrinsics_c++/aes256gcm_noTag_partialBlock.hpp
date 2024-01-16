#include <wmmintrin.h>
#include <cstdint>
#include <iostream>
#include <smmintrin.h>
#include <iomanip>  // Include this header for setw and setfill
#include "cpuProfiler.hpp"



class aes256Engine{
    public:

    aes256Engine(){}

    virtual ~aes256Engine(){}

    // For single block encrypt using AES
	void encrypt(const __m128i* plaintext, __m128i* ciphertext, __m128i* key_schedule) noexcept
	{
        *ciphertext = _mm_xor_si128(*plaintext, key_schedule[0]);
        for(auto iter=1; iter<14; iter++){
            *ciphertext = _mm_aesenc_si128(*ciphertext, key_schedule[iter]);
        }
		*ciphertext = _mm_aesenclast_si128(*ciphertext, key_schedule[14]);
	}

    // tested code
    void encrypt2(const __m128i& plaintext, __m128i& ciphertext, __m128i* key_schedule) noexcept //matched encryption with openssl
	{
        int number_of_rounds = 14; int j;
        __m128i tmp = _mm_loadu_si128 (&plaintext); 
        tmp = _mm_xor_si128 (tmp,((__m128i*)key_schedule)[0]); 
        for(j=1; j <number_of_rounds; j++){
            tmp = _mm_aesenc_si128 (tmp,((__m128i*)key_schedule)[j]); 
        }
        tmp = _mm_aesenclast_si128 (tmp,((__m128i*)key_schedule)[j]); 
        _mm_storeu_si128 (&ciphertext,tmp);
	}
};

class aes256gcm_EncryptContext{
    public:
    __m128i inputIV;
    __m128i encryptedIV;
    size_t encIV_unusedLen;
    __m128i key_schedule[15];

    aes256gcm_EncryptContext(){
        encIV_unusedLen =0;
    }
};

class aes256gcm_DecryptContext{
    public:
    __m128i inputIV;
    __m128i encryptedIV;
    size_t encIV_unusedLen;
    __m128i key_schedule[15];

    aes256gcm_DecryptContext(){
        encIV_unusedLen =0;
    }
};



class AES256GCM_NoTag_partialBlockFix{  
    aes256Engine *aesEngine;
    aes256gcm_EncryptContext *encObj;
    aes256gcm_DecryptContext *decObj;


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

    void load_key_256(__m128i *key_schedule, const uint8_t key[32]) noexcept
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

    // Expand the IV to a 128-bit block
    __inline__ void load_iv96(__m128i& storage, uint8_t* iv_96b) { //reduces intermediate variable
        // Load the original 96-bit IV directly into the first 128-bit block, avoiding an extra register and store operation
        _mm_storeu_si128(&storage, _mm_loadu_si128((__m128i*)iv_96b));

        // Combine zeroing and setting the last byte in a single instruction, then bitwise-OR
        storage = _mm_insert_epi8(storage, 0x01, 15);
    }


    __inline__ void inc32(__m128i& memory128b){
        static const __m128i SWAP_MASK = _mm_setr_epi8(0,1,2,3,4,5,6,7,8,9,10,11,15,14,13,12);
        memory128b = _mm_shuffle_epi8(_mm_add_epi32(_mm_shuffle_epi8(memory128b, SWAP_MASK), _mm_setr_epi32(0,0,0,1)), SWAP_MASK); 
    }


    public:
    AES256GCM_NoTag_partialBlockFix(){
        aesEngine = new aes256Engine();
    }
    ~AES256GCM_NoTag_partialBlockFix(){
    }
    void encrypt_aes256gcm_init(const uint8_t* key_encryption,  uint8_t* iv_encryption){
        encObj = new aes256gcm_EncryptContext();
        load_iv96(encObj->inputIV, iv_encryption);
        load_key_256(&(*encObj->key_schedule), key_encryption);
    }
    void decrypt_aes256gcm_init(const uint8_t* key_decryption,  uint8_t* iv_decryption){
        decObj = new aes256gcm_DecryptContext();
        load_iv96(decObj->inputIV, iv_decryption);
        load_key_256(&(*decObj->key_schedule), key_decryption);
    }

    void aes_gcm_encrypt(uint8_t* plaintext, size_t plaintext_len, uint8_t* ciphertext) {
        // Encrypt plaintext blocks
        for (size_t i = 0; i < plaintext_len; i += 16) {
            inc32(encObj->inputIV);
            aesEngine->encrypt2(encObj->inputIV, encObj->encryptedIV, encObj->key_schedule);

            // XOR plaintext with the encrypted counter block
            __m128i input_block = _mm_loadu_si128(reinterpret_cast<__m128i*>(plaintext + i));
            __m128i ciphertext_block = _mm_xor_si128(input_block, encObj->encryptedIV);
            _mm_storeu_si128((__m128i*)(ciphertext + i), ciphertext_block);
        }
    }

    
    void aes_gcm_decrypt(uint8_t* ciphertext, size_t ciphertext_len, uint8_t* plaintext) {
        // Decrypt ciphertext blocks
        for (size_t i = 0; i < ciphertext_len; i += 16) {
            inc32(decObj->inputIV);
            aesEngine->encrypt2(decObj->inputIV, decObj->encryptedIV, decObj->key_schedule); 

            // XOR ciphertext with the encrypted counter block to obtain the plaintext
            __m128i ciphertext_block = _mm_loadu_si128(reinterpret_cast<__m128i*>(ciphertext + i));
            __m128i plaintext_block = _mm_xor_si128(ciphertext_block, decObj->encryptedIV);
            _mm_storeu_si128((__m128i*)(plaintext + i), plaintext_block);
        }
    }

    // This function uses any pending iv bytes that was encrypted but not used
    void reuse_past_encryption(uint8_t* input, size_t& input_len, uint8_t* output){

    }

    void aes_gcm_encrypt_partialBlockFix(uint8_t* plaintext, size_t plaintext_len, uint8_t* ciphertext) {
        const size_t precompute_xor_len = std::min(encObj->encIV_unusedLen, plaintext_len);
        std::cout << "Cipher Len: " << plaintext_len << " unusedLen:  " << encObj->encIV_unusedLen << " precomputeXorLen: " << precompute_xor_len << std::endl;
        print_aes_block_singleLine("Last encrypted_iv", encObj->encryptedIV);

        // Section 1: XOR plaintext with the encrypted counter block for remaining bytes
        if (precompute_xor_len > 0) {
            // Load the remaining bytes from the encrypted IV
            const __m128i encrypted_suffix = _mm_loadu_si128(reinterpret_cast<__m128i*>(&encObj->encryptedIV) + (16 - encObj->encIV_unusedLen));
            print_aes_block_singleLine("encrypted_suffix", encrypted_suffix);

            // Create an __m128i variable with the first (16 - unused bytes) of plaintext
            const __m128i plaintext_suffix = _mm_loadu_si128(reinterpret_cast<__m128i*>(plaintext + plaintext_len - (16 - precompute_xor_len)));
            print_aes_block_singleLine("plaintext_suffix", plaintext_suffix);

            __m128i temp = _mm_xor_si128(plaintext_suffix, _mm_andnot_si128(_mm_setzero_si128(), encrypted_suffix));
            // Store the result in the first (16 - unused bytes) of ciphertext
            _mm_storeu_si128(reinterpret_cast<__m128i*>(ciphertext), temp);
            print_aes_block_singleLine("post XOR block", temp);
        }

        // Section 2: Encrypt plaintext blocks using newly encrypted iv
        for (size_t i = precompute_xor_len; i < plaintext_len; i += 16) {
            inc32(encObj->inputIV);
            aesEngine->encrypt(&encObj->inputIV, &encObj->encryptedIV, encObj->key_schedule);

            // XOR plaintext with the encrypted counter block
            __m128i input_block = _mm_loadu_si128(reinterpret_cast<__m128i*>(plaintext + i));
            __m128i ciphertext_block = _mm_xor_si128(input_block, encObj->encryptedIV);
            _mm_storeu_si128((__m128i*)(ciphertext + i), ciphertext_block);
        }

        // Section 3: Set aes256gcm_encryptMode_unusedEncIvLen to the remaining bytes
        encObj->encIV_unusedLen = (16 + precompute_xor_len - plaintext_len) % 16;
    }
    
    void aes_gcm_decrypt_partialBlockFix(uint8_t* ciphertext, size_t ciphertext_len, uint8_t* plaintext) {
        const size_t precompute_xor_len = std::min(decObj->encIV_unusedLen, ciphertext_len);
        
        // Section 1: XOR plaintext with the encrypted counter block for remaining bytes
        if (precompute_xor_len > 0) {
            // Load the remaining bytes from the encrypted IV
            const __m128i encrypted_suffix = _mm_loadu_si128(reinterpret_cast<__m128i*>(&decObj->encryptedIV) + (16 - decObj->encIV_unusedLen));

            // Create an __m128i variable with the first (16 - unused bytes) of plaintext
            const __m128i ciphertext_suffix = _mm_loadu_si128(reinterpret_cast<__m128i*>(ciphertext + ciphertext_len - (16 - precompute_xor_len)));

            __m128i temp = _mm_xor_si128(ciphertext_suffix, _mm_andnot_si128(_mm_setzero_si128(), encrypted_suffix));
            // Store the result in the first (16 - unused bytes) of ciphertext
            _mm_storeu_si128(reinterpret_cast<__m128i*>(plaintext), temp);
        }

        // Decrypt ciphertext blocks
        for (size_t i = precompute_xor_len; i < ciphertext_len; i += 16) {
            inc32(decObj->inputIV);
            aesEngine->encrypt(&decObj->inputIV, &decObj->encryptedIV, decObj->key_schedule); 

            // XOR ciphertext with the encrypted counter block to obtain the plaintext
            __m128i ciphertext_block = _mm_loadu_si128(reinterpret_cast<__m128i*>(ciphertext + i));
            __m128i plaintext_block = _mm_xor_si128(ciphertext_block, decObj->encryptedIV);
            _mm_storeu_si128((__m128i*)(plaintext + i), plaintext_block);
        }

        // Section 3: Set aes256gcm_encryptMode_unusedEncIvLen to the remaining bytes
        decObj->encIV_unusedLen = (16 + precompute_xor_len - ciphertext_len) % 16;
    }











    // Some print functions:
    void print_m128i(__m128i value) {
        std::cout<< "Printing 128bit register value: ";
        uint8_t bytes[16];
        _mm_storeu_si128((__m128i*)bytes, value);

        for (int i = 0; i < 16; ++i) {
            std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(bytes[i]);
        }
        std::cout << std::endl;
    }


    void print_aes_block_singleLine(std::string title, __m128i value) {
        uint8_t bytes[16];
        _mm_storeu_si128((__m128i*)bytes, value);

        std::cout << title << ": ";

        for (int i = 0; i < 16; ++i) {
            std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(bytes[i]) << " ";
        }
        std::cout << std::endl << std::endl;
    }


};