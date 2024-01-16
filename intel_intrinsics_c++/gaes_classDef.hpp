#include <cstdint>
#include <wmmintrin.h>

class AesCipher {
public:
    // Constructor
    AesCipher(const uint8_t* key, const uint8_t* iv);

    // Destructor
    ~AesCipher();

    // Encryption function
    void encrypt(const uint8_t* input, size_t inputLength, uint8_t* output);

    // Decryption function
    void decrypt(const uint8_t* input, size_t inputLength, uint8_t* output);

private:
    __m128i* roundKeys;  // Array to store round keys
    size_t keySize;      // Size of the encryption key in bytes
};


AesCipher::AesCipher(const uint8_t* key, const uint8_t* iv) {
    // Initialize key expansion based on the key size
    // You can modify this part based on your specific needs
    if (keySize == 16) {
        roundKeys = new __m128i[11];
        aes_helper_expand_key_128(reinterpret_cast<uint8_t*>(roundKeys), key);
    } else if (keySize == 32) {
        roundKeys = new __m128i[15];
        aes_helper_expand_key_256(reinterpret_cast<uint8_t*>(roundKeys), key);
    } else {
        // Handle other key sizes if needed
        // For example, you can add support for 192-bit keys
    }

    // Additional initialization steps, if any, can be added here
}

AesCipher::~AesCipher() {
    delete[] roundKeys;
}

void AesCipher::encrypt(const uint8_t* input, size_t inputLength, uint8_t* output) {
    // Perform AES encryption here
    // You can use the provided aes_helper_encrypt_block_128, etc.
    // Remember to handle padding and multiple blocks if needed
}

void AesCipher::decrypt(const uint8_t* input, size_t inputLength, uint8_t* output) {
    // Perform AES decryption here
    // You can use the provided aes_helper_decrypt_block_128, etc.
    // Remember to handle padding and multiple blocks if needed
}


