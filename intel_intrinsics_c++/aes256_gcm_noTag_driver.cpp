#include "aes256gcm_noTag_partialBlock.hpp"
#include <cstdint>
#include <string.h>     //for memcmp

#include "cpuProfiler.hpp"
#include "random.hpp"
#define MAX_OP 50
using namespace std;

// Change these constants for AES-256
const bool MATCH_MODE = true;
const bool PRINT_ALL_DATA = true;
const bool PRINT_IV = true;
const int AES_KEY_SIZE = 32;  // 256 bits
const int AES_IV_SIZE = 12;  // 96 bits
const int AES_BLOCK_SIZE = 16;  // 128 bits
const int AES_INPUT_SIZE = 34;
const int WARM_UP_CYCLE = 0;

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
    if(MATCH_MODE){
        key = r.hexStringToByteArray("49 74 6b 75 79 53 72 5d 51 78 49 6a 5f 79 53 63 6b 74 6a 4e 6f 79 5d 4e 4c 79 5a 4f 58 65 51 70", AES_KEY_SIZE);
        iv  = r.hexStringToByteArray("78 5b 54 60 4e 66 72 58 4d 74 62 4c", AES_IV_SIZE);
    }
    else{
        key = r.getRandomUint8(AES_KEY_SIZE);
        iv = r.getRandomUint8(AES_IV_SIZE); //32 char key, 12 char iv 
    }

	//initialize intel aes-256-gcm class object with key and iv
    AES256GCM_NoTag_partialBlockFix aesObj;
    //aesObj.print_all_keys();
    // __m128i computed_cipher, computed_plain;


	cout << "======================================================== Using INTEL AES256-GCM with Plaintext Size: " << AES_INPUT_SIZE << endl;
	cout << "Random 32-byte Key: ";
	r.print_uint8_Array_hex(key, AES_KEY_SIZE);
	cout << "Random 12-byte IV: ";
	r.print_uint8_Array_hex(iv, AES_IV_SIZE);
	cout << "Starting Excryption/Decryption for " << MAX_OP << " times..." << endl;

	aesObj.encrypt_aes256gcm_init(key, iv);
	aesObj.decrypt_aes256gcm_init(key, iv);

	// Warm Up
    for( int iter=0; iter< WARM_UP_CYCLE; iter++){
        uint8_t *plain = r.getRandomUint8(AES_INPUT_SIZE);
		aesObj.aes_gcm_encrypt(plain, AES_INPUT_SIZE, computed_cipher);
		aesObj.aes_gcm_decrypt(computed_cipher, AES_INPUT_SIZE, computed_plain);
	}

	// Actual Simulation starts below
	for( int iter=0; iter< MAX_OP; iter++){
        // determine plaintext
        if(MATCH_MODE){
            //plain = r.hexStringToByteArray("50 62 53 52 64 51 5b 6d 71 63 78 77 5e 7a 51 00 50 62 53 52 64 51 5b 6d 71 63 78 77 5e 7a 51 00", AES_INPUT_SIZE);
            //plain = r.hexStringToByteArray("00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00", AES_INPUT_SIZE);
            //plain = r.hexStringToByteArray("50 62 53 52 64 51 5b 6d 71 63 78 77 5e 7a 51 00 50 62 53 52", AES_INPUT_SIZE);
            //plain = r.hexStringToByteArray("50 62 53 52 64 51 5b 6d 71 63 78 77 5e 7a 51 00 50 62 53 52 64 51 5b 6d 71 63 78 77 5e 7a 51 00 50 62 53 52 64 51 5b 6d 71 63 78 77 5e 7a 51 00 50 62 53 52 64 51 5b 6d 71 63 78 77 5e 7a 51 00", AES_INPUT_SIZE);
            //plain = r.hexStringToByteArray("50 62 53 52 64 51 5b 6d 71 63 78 77 5e 7a 51 00 50 62 53 52 64 51 5b 6d 71 63 78 77 5e 7a 51 ", AES_INPUT_SIZE);
            plain = r.hexStringToByteArray("00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00", AES_INPUT_SIZE);
        }
        else plain = r.getRandomStringUnsigned(AES_INPUT_SIZE);

		CpuProfiler::getUniqueInstance().startTag("EncryptTime");
		aesObj.aes_gcm_encrypt_partialBlockFix(plain, AES_INPUT_SIZE, computed_cipher);
		CpuProfiler::getUniqueInstance().stopTag("EncryptTime");

		CpuProfiler::getUniqueInstance().startTag("DecryptTime");
		aesObj.aes_gcm_decrypt_partialBlockFix(computed_cipher, AES_INPUT_SIZE, computed_plain);
		CpuProfiler::getUniqueInstance().stopTag("DecryptTime");

		if(PRINT_ALL_DATA){
			//cout << "PT: ";
			//r.print_uint8_Array_hex(plain, AES_INPUT_SIZE);
			cout << "CT "<< std::dec << iter << "\t" ;
			r.print_uint8_Array_hex(computed_cipher, AES_INPUT_SIZE);
			//cout << "PT':";
			//r.print_uint8_Array_hex(computed_plain, AES_INPUT_SIZE);
		}

		if(PRINT_IV){
			string title = "Final IV at iter " + to_string(iter) + "\t" ;
			//aesObj.print_aes_block_singleLine(title, *aesObj.counter_block_enc);
		}
	}
    CpuProfiler::getUniqueInstance().prepareReportAndDumpToFile();

	if(MATCH_MODE){ //prints only last output
        cout << "Printing the last PT, CT and decrypted CT (PT'):\n";
		cout << "PT: \t";
		r.print_uint8_Array_hex(plain, AES_INPUT_SIZE);
		cout << "CT: \t";
		r.print_uint8_Array_hex(computed_cipher, AES_INPUT_SIZE);
		cout << "PT':\t";
		r.print_uint8_Array_hex(computed_plain, AES_INPUT_SIZE);

        if (0 == memcmp(plain, computed_plain, sizeof(AES_INPUT_SIZE)))
            std::cout << "Plaintext matched \U0001F604\n"; // Unicode for :) smiley
        else std::cout << "Plaintext mismatch \U0001F61E\n"; // Unicode for :( sad face
	}

    return 0;
}