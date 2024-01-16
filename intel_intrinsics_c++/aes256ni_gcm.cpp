#include <wmmintrin.h>
#include <cstdint>
#include <iostream>

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

void AES_256_Key_Expansion(const uint8_t key[32], __m128i expanded_key[15]) noexcept
{
    expanded_key[0] = _mm_loadu_si128(reinterpret_cast<const __m128i*>(&key[0]));
    expanded_key[1] = _mm_loadu_si128(reinterpret_cast<const __m128i*>(&key[16]));

    for (int i = 2; i < 15; i += 2){
        expanded_key[i] = aes_expand_key_evn_step(expanded_key[i - 2], _mm_aeskeygenassist_si128(expanded_key[i - 1], 0x01));
        expanded_key[i + 1] = aes_expand_key_odd_step(expanded_key[i], expanded_key[i - 1]);
    }
}



void aes_gcm_encrypt(uint8_t* plaintext, size_t plaintext_len,
                    const uint8_t* key, uint8_t* iv, uint8_t* ciphertext,
                    uint8_t* auth_tag) {
    // Expand the AES key
    __m128i key_schedule[15];
    AES_256_Key_Expansion(key, key_schedule);

    // Expand the IV to a 128-bit block
    __m128i extended_iv[2];
    AES_iv_expansion(iv, extended_iv);

    // Initialize counter block
    __m128i counter_block = extended_iv[0];

    // Initialize GHASH state
    __m128i ghash_state = _mm_setzero_si128();

    // Encrypt plaintext blocks
    for (size_t i = 0; i < plaintext_len; i += 16) {
        // Encrypt the counter block using full AES round function
        __m128i encrypted_counter_block = _mm_aesenc_si128(counter_block, key_schedule[0]);
        for (int j = 1; j < 14; j++) {
            encrypted_counter_block = _mm_aesenc_si128(encrypted_counter_block, key_schedule[j]);
        }
        encrypted_counter_block = _mm_aesenclast_si128(encrypted_counter_block, key_schedule[14]);

        // XOR plaintext with the encrypted counter block
        __m128i input_block = _mm_loadu_si128(reinterpret_cast<__m128i*>(plaintext + i));
        __m128i ciphertext_block = _mm_xor_si128(input_block, encrypted_counter_block);
        _mm_storeu_si128((__m128i*)(ciphertext + i), ciphertext_block);

        // Update GHASH state
        ghash_state = _mm_clmulepi64_si128(ghash_state, key_schedule[0], 0x10);
        ghash_state = _mm_xor_si128(ghash_state, _mm_xor_si128(input_block, ciphertext_block));

        // Increment counter block for the next block
        counter_block = _mm_add_epi64(counter_block, _mm_set_epi64x(0, 1));
    }

    // Finalize GHASH and generate authentication tag
    // ... (Implementation for final GHASH steps and tag generation)

    // Store the authentication tag
    _mm_storeu_si128((__m128i*)auth_tag, tag);
}

void aes_gcm_decrypt(uint8_t* ciphertext, size_t ciphertext_len,
                    const uint8_t* key, const uint8_t* iv, uint8_t* plaintext,
                    const uint8_t* auth_tag) {
    // Expand the AES key
    __m128i key_schedule[15];
    AES_256_Key_Expansion(key, key_schedule);

    // Expand the IV to a 128-bit block
    __m128i extended_iv[2];
    AES_iv_expansion(iv, extended_iv);

    // Initialize counter block
    __m128i counter_block = extended_iv[0];

    // Initialize GHASH state
    __m128i ghash_state = _mm_setzero_si128();

    // Decrypt ciphertext blocks
    for (size_t i = 0; i < ciphertext_len; i += 16) {
        // Encrypt the counter block using full AES round function (same as encryption)
        __m128i encrypted_counter_block = _mm_aesenc_si128(counter_block, key_schedule[0]);
        for (int j = 1; j < 14; j++) {
            encrypted_counter_block = _mm_aesenc_si128(encrypted_counter_block, key_schedule[j]);
        }
        encrypted_counter_block = _mm_aesenclast_si128(encrypted_counter_block, key_schedule[14]);

        // XOR ciphertext with the encrypted counter block to get plaintext
        __m128i ciphertext_block = _mm_loadu_si128(reinterpret_cast<__m128i*>(ciphertext + i));
        __m128i plaintext_block = _mm_xor_si128(ciphertext_block, encrypted_counter_block);
        _mm_storeu_si128((__m128i*)(plaintext + i), plaintext_block);

        // Update GHASH state (same as encryption)
        ghash_state = _mm_clmulepi64_si128(ghash_state, key_schedule[0], 0x10);
        ghash_state = _mm_xor_si128(ghash_state, _mm_xor_si128(plaintext_block, ciphertext_block));

        // Increment counter block for the next block
        counter_block = _mm_add_epi64(counter_block, _mm_set_epi64x(0, 1));
    }

    // Finalize GHASH and generate the calculated authentication tag
    __m128i len_block = _mm_set_epi64x(0, ciphertext_len * 8);  // Length in bits
    ghash_state = _mm_clmulepi64_si128(ghash_state, key_schedule[0], 0x10);
    ghash_state = _mm_xor_si128(ghash_state, len_block);  // Include length in GHASH
    ghash_state = _mm_clmulepi64_si128(ghash_state, key_schedule[0], 0x10);
    __m128i auth_tag_calculated = _mm_xor_si128(ghash_state, key_schedule[0]);

    // Compare the calculated tag with the provided auth_tag
    if (_mm_test_all_zeros(_mm_xor_si128(auth_tag_calculated, _mm_loadu_si128((__m128i*)auth_tag)), _mm_set1_epi8(0xFF))) {
        // Decryption successful
    } else {
        // Authentication failure
    }
}


void aes_gcm_encrypt_incomplete(uint8_t* plaintext, size_t plaintext_len,
                    const uint8_t* key, const uint8_t* iv, uint8_t* ciphertext) {
    // Expand the AES key
    __m128i key_schedule[15];
    //uint8_t key_schedule[240];

    AES_256_Key_Expansion(key, key_schedule);

    // Initialize counter block
    __m128i counter_block = _mm_set_epi64x(0, 1);

    // Encrypt the counter block to generate the initial counter value
    __m128i encrypted_counter_block = _mm_aesenc_si128(counter_block,  key_schedule[0]);

    // XOR the plaintext with the encrypted counter block
    for (size_t i = 0; i < plaintext_len; i += 16) {
        __m128i input_block = _mm_loadu_si128(reinterpret_cast<__m128i*>(plaintext + i));
        __m128i ciphertext_block = _mm_xor_si128(input_block, encrypted_counter_block);
        _mm_storeu_si128((__m128i*)(ciphertext + i), ciphertext_block);

        // Increment the counter for the next block
        counter_block = _mm_add_epi64(counter_block, _mm_set_epi64x(0, 1));

        // Encrypt the updated counter block
        encrypted_counter_block = _mm_aesenc_si128(counter_block, key_schedule[0]);
    }
}


void aes_gcm_decrypt_incomplete(uint8_t* ciphertext, size_t ciphertext_len,
                    const uint8_t* key, const uint8_t* iv, uint8_t* decryptedtext) {
    // Expand the AES key
    __m128i key_schedule[15];
    //uint8_t key_schedule[240];

    AES_256_Key_Expansion(key, key_schedule);

    // Initialize counter block
    __m128i counter_block = _mm_set_epi64x(0, 1);

    // Encrypt the counter block to generate the initial counter value
    __m128i encrypted_counter_block = _mm_aesenc_si128(counter_block, key_schedule[0]);

    // XOR the ciphertext with the encrypted counter block to decrypt
    for (size_t i = 0; i < ciphertext_len; i += 16) {
        __m128i input_block = _mm_loadu_si128(reinterpret_cast<__m128i*>(ciphertext + i));
        __m128i decrypted_block = _mm_xor_si128(input_block, encrypted_counter_block);
        _mm_storeu_si128(reinterpret_cast<__m128i*>(decryptedtext + i), decrypted_block);

        // Increment the counter for the next block
        counter_block = _mm_add_epi64(counter_block, _mm_set_epi64x(0, 1));

        // Encrypt the updated counter block for the next iteration
        encrypted_counter_block = _mm_aesenc_si128(counter_block, key_schedule[0]);
    }
}

// GHASH function using Intel Intrinsics
void ghash(const uint8_t* hashkey_128b, const uint8_t* input_128b, size_t input_len, uint8_t* result) {
    __m128i h_block = _mm_loadu_si128(reinterpret_cast<const __m128i*>(hashkey_128b));
    __m128i y = _mm_setzero_si128();

    for (size_t i = 0; i < input_len; i += 16) {
        __m128i x_block = _mm_loadu_si128(reinterpret_cast<const __m128i*>(input_128b + i));
        y = _mm_xor_si128(y, x_block);
        y = _mm_clmulepi64_si128(y, h_block, 0x00); //Galois field multiplication for 128-bit blocks
    }

    _mm_storeu_si128(reinterpret_cast<__m128i*>(result), y);
}


void gctr_encrypt(const uint8_t* plaintext, size_t plaintext_len,
                  const uint8_t* key, const uint8_t* iv, uint8_t* ciphertext) {
    // Expand the AES key
    __m128i key_schedule[15];
    AES_256_Key_Expansion(key, key_schedule);

    // Set the initial counter block
    __m128i counter_block = _mm_setzero_si128();
    __m128i iv_block = _mm_loadu_si128(reinterpret_cast<const __m128i*>(iv));

    // Encrypt each block in GCTR mode
    for (size_t i = 0; i < plaintext_len; i += 16) {
        // Increment the counter for the next block
        counter_block = _mm_add_epi64(counter_block, _mm_set_epi64x(0, 1));

        // XOR the counter with the IV to create the keystream
        __m128i keystream = _mm_xor_si128(counter_block, iv_block);

        // Encrypt the keystream with the key
        keystream = _mm_aesenc_si128(keystream, key_schedule[0]);

        // XOR the plaintext with the keystream to produce the ciphertext
        __m128i plaintext_block = _mm_loadu_si128(reinterpret_cast<const __m128i*>(plaintext + i));
        __m128i ciphertext_block = _mm_xor_si128(plaintext_block, keystream);

        // Store the ciphertext
        _mm_storeu_si128(reinterpret_cast<__m128i*>(ciphertext + i), ciphertext_block);
    }
}


void gctr_decrypt(const uint8_t* ciphertext, size_t ciphertext_len,
                  const uint8_t* key, const uint8_t* iv, uint8_t* plaintext) {
    // Expand the AES key
    __m128i key_schedule[15];
    AES_256_Key_Expansion(key, key_schedule);

    // Set the initial counter block
    __m128i counter_block = _mm_setzero_si128();
    __m128i iv_block = _mm_loadu_si128(reinterpret_cast<const __m128i*>(iv));

    // Decrypt each block in GCTR mode
    for (size_t i = 0; i < ciphertext_len; i += 16) {
        // Increment the counter for the next block
        counter_block = _mm_add_epi64(counter_block, _mm_set_epi64x(0, 1));

        // XOR the counter with the IV to create the keystream
        __m128i keystream = _mm_xor_si128(counter_block, iv_block);

        // Encrypt the keystream with the key
        keystream = _mm_aesenc_si128(keystream, key_schedule[0]);

        // XOR the ciphertext with the keystream to produce the plaintext
        __m128i ciphertext_block = _mm_loadu_si128(reinterpret_cast<const __m128i*>(ciphertext + i));
        __m128i plaintext_block = _mm_xor_si128(ciphertext_block, keystream);

        // Store the plaintext
        _mm_storeu_si128(reinterpret_cast<__m128i*>(plaintext + i), plaintext_block);
    }





int main() {
    // Example usage
    const uint8_t key[32] = {0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x97, 0x87, 0x7a, 0xe9, 0x6f, 0x22, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x97, 0x87, 0x7a, 0xe9, 0x6f, 0x22, 0xae, 0xd2, 0xa6, 0xab, 0xf7};
    uint8_t plaintext1[16] = "Hello, AES-GCM!";
    uint8_t ciphertext1[16];
    uint8_t decryptedtext1[16];

    // Encryption
    aes_gcm_encrypt(plaintext1, 16, key, nullptr, ciphertext1);

    // Decryption
    aes_gcm_decrypt(ciphertext1, 16, key, nullptr, decryptedtext1);

    // Display results
    std::cout << "Plaintext: " << plaintext1 << std::endl;
    std::cout << "Ciphertext: ";
    for (int i = 0; i < 16; ++i) {
        printf("%02x ", ciphertext1[i]);
    }
    std::cout << std::endl;
    std::cout << "Decryptedtext: " << decryptedtext1 << std::endl;



    //GHASH Outputs
    //uint8_t hashkey_128b[16] = "0123456789ABCDEF";
    uint8_t hashkey_128b[16] = {0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46};
    uint8_t input_128b[32] = "Hello, GHASH!";
    uint8_t result[16];

    ghash(hashkey_128b, input_128b, sizeof(input_128b), result);
    std::cout << "GHASH: ";
    for (int i = 0; i < 16; ++i) {
        printf("%02x ", result[i]);
    }


    // GCTR Enc Example usage
    uint8_t key[32] = "0123456789ABCDEF0123456789ABCDEF";
    uint8_t iv[16] = "0123456789ABCDEF";
    uint8_t plaintext2[32] = "Hello, this is a test!";
    uint8_t ciphertext2[32];

    gctr_encrypt(plaintext2, sizeof(plaintext2), key, iv, ciphertext2);

    // Display the ciphertext (in hexadecimal)
    for (size_t i = 0; i < sizeof(ciphertext2); ++i) {
        printf("%02X ", ciphertext2[i]);
    }


    // GCTR Dec Example usage
    uint8_t key[32] = "0123456789ABCDEF0123456789ABCDEF";
    uint8_t iv[16] = "0123456789ABCDEF";
    uint8_t plaintext3[32] = "Hello, this is a test!";
    uint8_t ciphertext3[32];
    uint8_t decrypted_text3[32];

    // Encrypt plaintext
    gctr_encrypt(plaintext2, sizeof(plaintext2), key, iv, ciphertext3);

    // Decrypt ciphertext
    gctr_decrypt(ciphertext3, sizeof(ciphertext3), key, iv, decrypted_text3);

    // Display the decrypted text
    printf("Decrypted Text: %s\n", decrypted_text3);

    return 0;
}

