#include "aes256-gcm_noTag.cpp"
#include "random.hpp"
using namespace std;

unsigned char* hexStringToByteArray(const std::string& hexString, int k) {
    std::istringstream hexStream(hexString);
    hexStream >> std::hex;  // Set the stream to read hex values

    // Create an array to store the result
    unsigned char* result = new unsigned char[k];

    // Read k values from the hex string
    for (int i = 0; i < k; ++i) {
        int value;
        hexStream >> value;

        // Ensure the value is within the valid range for unsigned char
        result[i] = static_cast<unsigned char>(value);
    }
    return result;
}


int main(){
    RandomNumC r;
    unsigned char *key, *iv;
    key = r.hexStringToByteArray("49 74 6b 75 79 53 72 5d 51 78 49 6a 5f 79 53 63 6b 74 6a 4e 6f 79 5d 4e 4c 79 5a 4f 58 65 51 70", 32);
    iv  = r.hexStringToByteArray("78 5b 54 60 4e 66 72 58 4d 74 62 4c", 12);
    

    AES256_GCM_NoTag obj;
    obj.initialize(key, iv);


    __m128i plaintext, cipherText;
    uint8_t* input;
    input = r.hexStringToByteArray("86 ec 31 a5 64 01 79 79 84 83 5f 18 50 80 3a 9f", 16);
    input = r.hexStringToByteArray("7b a4 4d 90 d2 64 1c 1c d6 52 68 38 0a 33 f2 3c", 16);
    input = r.hexStringToByteArray("ec 31 a5 64 01 79 79 84 83 5f 18 50 80 3a 9f 5c", 16);
    
    _mm_storeu_si128(&cipherText, _mm_loadu_si128((__m128i*)input));

    obj.print_aes_block_singleLine("Input Ciphertext: ", cipherText);

    obj.decrypt_iv(&cipherText, &plaintext);
    obj.print_aes_block_singleLine("Decrypted plaintext: ", plaintext);
    obj.encrypt_iv(&plaintext, &cipherText);
    obj.print_aes_block_singleLine("Reencrypted plaintext: ", cipherText);


    return 0;
}