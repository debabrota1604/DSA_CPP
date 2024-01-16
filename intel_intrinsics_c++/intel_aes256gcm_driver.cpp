#include "aes256gcm_noTag_partialBlock.hpp"
#include <cstdint>
#include <string.h>     //for memcmp

#include "cpuProfiler.hpp"
#include "random.hpp"
#define MAX_OP 10000
using namespace std;

// Change these constants for AES-256
const int AES_KEY_SIZE = 32;  // 256 bits
const int AES_IV_SIZE = 12;  // 96 bits
const int AES_BLOCK_SIZE = 16;  // 128 bits
const int AES_INPUT_SIZE = 300;

int main() {
    RandomNumC r;
    unsigned char *key, *iv, *plain;
    uint8_t computed_cipher[AES_INPUT_SIZE]; 
    uint8_t computed_plain[AES_INPUT_SIZE];

    // Initialize profiler object and tags
    CpuProfiler::getUniqueInstance();    
    CpuProfiler::getUniqueInstance().addTag("EncryptTime");
    CpuProfiler::getUniqueInstance().addTag("DecryptTime");

	// initialize key and iv
    key = r.getRandomUint8(AES_KEY_SIZE);
    iv = r.getRandomUint8(AES_IV_SIZE); //32 char key, 12 char iv 

	//initialize intel aes-256-gcm class object with key and iv
    AES256GCM_NoTag_partialBlockFix aesObj;


	cout << "======================================================== Using INTEL AES256-GCM with Plaintext Size: " << AES_INPUT_SIZE << endl;
	cout << "Random 32-byte Key: ";
	r.print_uint8_Array_hex(key, AES_KEY_SIZE);
	cout << "Random 12-byte IV: ";
	r.print_uint8_Array_hex(iv, AES_IV_SIZE);
	cout << "====================================== Looping for " << MAX_OP << " times ======================================" << endl;

	aesObj.encrypt_aes256gcm_init(key, iv);
	aesObj.decrypt_aes256gcm_init(key, iv);

	// Actual Simulation starts below
	for( int iter=0; iter< MAX_OP; iter++){
        plain = r.getRandomStringUnsigned(AES_INPUT_SIZE);

		CpuProfiler::getUniqueInstance().startTag("EncryptTime");
		aesObj.aes_gcm_encrypt_partialBlockFix(plain, AES_INPUT_SIZE, computed_cipher);
		CpuProfiler::getUniqueInstance().stopTag("EncryptTime");

		CpuProfiler::getUniqueInstance().startTag("DecryptTime");
		aesObj.aes_gcm_decrypt_partialBlockFix(computed_cipher, AES_INPUT_SIZE, computed_plain);
		CpuProfiler::getUniqueInstance().stopTag("DecryptTime");

		
	}
    CpuProfiler::getUniqueInstance().prepareReportAndDumpToFile();

    return 0;
}