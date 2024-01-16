#include "aes256_ni.cpp"
#include <cstdint>
#include <string.h>     //for memcmp

#include "cpuProfiler.hpp"
#include "random.hpp"
#define MAX_OP 10000
using namespace std;



// // Change these constants for AES-256
// const int AES_KEY_SIZE = 32;  // 256 bits
// const int AES_BLOCK_SIZE = 16;  // 128 bits



int main() {
	cout << "CheckText\n";
    RandomNumC r;
    CpuProfiler::getUniqueInstance();    
    CpuProfiler::getUniqueInstance().addTag("EncryptTime");
    CpuProfiler::getUniqueInstance().addTag("DecryptTime");


    unsigned char *key = r.getRandomUint8(AES_KEY_SIZE); //, *iv = r.getRandomUint8(12); //32 char key, 12 char iv 
	cout << "Random 32-byte Key: ";
	r.print_uint8_Array(key, AES_KEY_SIZE);

    uint8_t roundKeys[240];
    AES256Engine aesObj;
    aesObj.load_key_256(roundKeys, key);

    uint8_t computed_cipher[AES_BLOCK_SIZE]; 
    uint8_t computed_plain[AES_BLOCK_SIZE];

	cout << "Starting Excryption/Decryption for " << MAX_OP << " times..." << endl;
    for( int iter=0; iter< MAX_OP; iter++){
        uint8_t *plain = r.getRandomUint8(AES_BLOCK_SIZE);


		CpuProfiler::getUniqueInstance().startTag("EncryptTime");
		aesObj.encrypt_block_256(plain, computed_cipher, roundKeys);
		CpuProfiler::getUniqueInstance().stopTag("EncryptTime");

		CpuProfiler::getUniqueInstance().startTag("DecryptTime");
		aesObj.decrypt_block_256(computed_cipher, computed_plain, roundKeys);
		CpuProfiler::getUniqueInstance().stopTag("DecryptTime");

		// cout << "PT: ";
		// r.print_uint8_Array(plain, AES_KEY_SIZE);
		// cout << "CT: ";
		// r.print_uint8_Array(computed_cipher, AES_KEY_SIZE);
		// cout << "PT':";
		// r.print_uint8_Array(computed_plain, AES_KEY_SIZE);

		// if(0 == memcmp(cipher,computed_cipher,sizeof(cipher)))
		// 	printf("Ciphertext matched :)\n");
		// else printf("Ciphertext mismatch :(\n");

		// if(0 == memcmp(plain,computed_plain,sizeof(AES_KEY_SIZE))) printf("Plaintext matched :)\n");
		// else printf("Plaintext mismatch :(\n");
	}
    CpuProfiler::getUniqueInstance().prepareReportAndDumpToFile();

    return 0;
}