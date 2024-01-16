
#include <string.h>

#include "ippcp.h"
#include "examples_common.h"
#include <iostream>


#define MAX_CRYPTO_BUFFER_LENGTH 8192
#define SRC_LEN 250

class IntelCryptoEngine{
  public :
    /*! AES block size in bytes */
    //static const int AES_BLOCK_SIZE = 16;
    static const int AES_BLOCK_SIZE = 12;

    /*! Key size in bytes */
    static const int KEY_SIZE = 32;

    /* Length of changeable bits in a counter (can be value starting from 1 till block size 128) */
    const Ipp32u counterLen;

    /* Size of AES context structure. It will be set up in ippsAESGetSize(). */
    int ctxSize;

    // Arrays
    Ipp8u *encOutput, *decOutput, *initialCounter, *pCounter;


    /* Pointer to AES context structure */
    IppsAESSpec *encrypt_ctx=0, *decrypt_ctx=0;
    int encrypt_len, decrypt_len;

    /* Internal function status */
    int status = ippStsNoErr;

    IntelCryptoEngine():
      initialCounter(new unsigned char[AES_BLOCK_SIZE]),
      pCounter(new unsigned char[AES_BLOCK_SIZE]),
      encrypt_ctx(nullptr),
      decrypt_ctx(nullptr),
      encOutput(new unsigned char[SRC_LEN]),
      decOutput(new unsigned char[SRC_LEN]),
      encrypt_len(0),
      decrypt_len(0),
      counterLen(128),
      ctxSize(0){

        /* 1. Get size needed for AES context structure */
        status = ippsAESGetSize(&ctxSize);

        if (!checkStatus("ippsAESGetSize", ippStsNoErr, status))
            std::cout << "ippsAESGetSize not configured properly\n";

        /* 2. Allocate memory for AES context structure */
        encrypt_ctx = (IppsAESSpec*)(new Ipp8u[ctxSize]);
        if(NULL == encrypt_ctx){
            std::cout << "EncInit ERROR: Cannot allocate memory " << ctxSize << " for AES Encrypt context" << std::endl;
        }

        /* 2. Allocate memory for AES context structure */
        decrypt_ctx = (IppsAESSpec*)(new Ipp8u[ctxSize]);
        if (NULL == decrypt_ctx) {
            std::cout << "DecInit ERROR: Cannot allocate memory " << ctxSize << " for AES Decrypt context" << std::endl;
        }
    }

    ~IntelCryptoEngine(){}

    void encrypt_EVP_aes_256_gcm_init(unsigned char *key, unsigned char *iv){
        //this->initialCounter = iv; //doing once assuming both iv will be same
        memcpy(this->initialCounter, iv, AES_BLOCK_SIZE);
        /* 3. Initialize AES context */
        status = ippsAESInit(key, 32, encrypt_ctx, ctxSize);
        //std::cout << "Encrypt Status: " << status << "\n\n";
        if (!checkStatus("ippsAESInit", ippStsNoErr, status))
            std::cout << "FAILED TO INITIALIZE CRYPTO AES 256 Encryption" << std::endl;
    }

    void decrypt_EVP_aes_256_gcm_init(unsigned char *key, unsigned char *iv){
        /* 3. Initialize AES context */
        status = ippsAESInit(key, 32, decrypt_ctx, ctxSize);
        //std::cout << "Decrypt Status: " << status << "\n\n";
        if (!checkStatus("ippsAESInit", ippStsNoErr, status))
            std::cout << "FAILED TO INITIALIZE CRYPTO AES 256 Decryption" << std::endl;
    }

    void aes_encrypt(unsigned char *plainText, int plainText_len){ // plainText len between 220 to 290 bytes
        /* Initialize counter before encryption.
         * An updated counter value will be stored here after ippsAESEncryptCTR finishes.
         */
        memcpy(pCounter, initialCounter, AES_BLOCK_SIZE);

        /* 4. Encryption */
        status = ippsAESEncryptCTR(plainText, encOutput, plainText_len, encrypt_ctx, pCounter, counterLen);
        if (!checkStatus("ippsAESEncryptCTR", ippStsNoErr, status))
            std::cout << "Errors in encrypting msg...\n";

}

    void aes_decrypt(unsigned char *cipherText, int cipherText_len){
        /* Initialize counter before decryption.
         * An updated counter value will be stored here after ippsAESDecryptCTR finishes.
         */
        memcpy(pCounter, initialCounter, AES_BLOCK_SIZE);

        /* 4. Decryption */
        status = ippsAESDecryptCTR(cipherText, decOutput, cipherText_len, decrypt_ctx, pCounter, counterLen);
        if (!checkStatus("ippsAESDecryptCTR", ippStsNoErr, status))
            std::cout << "Errors in decrypting msg...\n";

    }

    void aes_decrypt_wrapper(){
        /* Initialize counter before decryption.
         * An updated counter value will be stored here after ippsAESDecryptCTR finishes.
         */
        memcpy(pCounter, initialCounter, AES_BLOCK_SIZE);

        /* 4. Decryption */
        status = ippsAESDecryptCTR(encOutput, decOutput, SRC_LEN, decrypt_ctx, pCounter, counterLen);
        if (!checkStatus("ippsAESDecryptCTR", ippStsNoErr, status))
            std::cout << "Errors in decrypting msg...\n";
    }

    void compare_plaintext_ciphertext(){
        /* Compare decrypted message and original text */
        if (0 != memcmp(encOutput, decOutput, encrypt_len)) {
            printf("ERROR: Decrypted and plain text messages do not match\n");
        }
    }

    unsigned char* getEncryptedMsg(){ return this->encOutput;}
    unsigned char* getDecryptedMsg(){ return this->decOutput;}
};
