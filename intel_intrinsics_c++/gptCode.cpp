#include <iostream>
#include <iomanip>  // Include this header for setw and setfill
#include <ippcp.h>

void encrypt(const Ipp8u* plaintext, const Ipp8u* key, Ipp8u* ciphertext) {
    IppsAESSpec* pCtx;
    ippsAESInit(key, 32, &pCtx, ipp_AES192 | ipp_AESKeyGen192);

    ippsAESEncryptECB(plaintext, ciphertext, 16, pCtx);

    ippsAESFree(pCtx);
}

void decrypt(const Ipp8u* ciphertext, const Ipp8u* key, Ipp8u* decryptedText) {
    IppsAESSpec* pCtx;
    ippsAESInit(key, 32, &pCtx, ipp_AES192 | ipp_AESKeyGen192);

    ippsAESDecryptECB(ciphertext, decryptedText, 16, pCtx);

    ippsAESFree(pCtx);
}

int main() {
    // Example key (256-bit key for AES-256)
    Ipp8u key[32] = {0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x97, 0x6e, 0x65, 0x7a, 0x08, 0x2f,
                     0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x97, 0x6e, 0x65, 0x7a, 0x08, 0x2f};

    // Example plaintext (16 bytes)
    Ipp8u plaintext[16] = "Hello, AES-NI!";

    // Allocate memory for ciphertext and decryptedText
    Ipp8u ciphertext[16];
    Ipp8u decryptedText[16];

    // Encrypt
    encrypt(plaintext, key, ciphertext);

    // Decrypt
    decrypt(ciphertext, key, decryptedText);

    // Display results
    std::cout << "Original Text: " << plaintext << std::endl;
    std::cout << "Encrypted Text: ";
    for (int i = 0; i < 16; ++i) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(ciphertext[i]);
    }
    std::cout << std::dec << std::endl;

    std::cout << "Decrypted Text: " << decryptedText << std::endl;

    return 0;
}
