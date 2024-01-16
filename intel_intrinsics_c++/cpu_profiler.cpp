#include<bits/stdc++.h>
#include "dvccode/Utils/cpuProfiler.hpp"
#include "dvccode/Utils/random.hpp"
#include "dvccode/Utils/openssl_crypto_engine.hpp"
// #include "/home/dvctrader/Deb/openSSL/openssl/crypto/evp/evp_enc.c"
using namespace std;


#define MAX_OP 10000
#define MSG_LEN 250

void printCharArray(const unsigned char *inp){
    unsigned long leng=0;
    while(inp[leng++] != '\0');
    printf("Array size: %lu, contents: [%s]\n", leng, inp);
}

int main(){
    RandomNumC r;
    CpuProfiler::getUniqueInstance();    
    CpuProfiler::getUniqueInstance().addTag("EncryptTime");
    CpuProfiler::getUniqueInstance().addTag("DecryptTime");


    unsigned char *key = r.getRandomStringUnsigned(32), *iv = r.getRandomStringUnsigned(12); //32 char key, 12 char iv 


        // cout << "key: " << sizeof(*key) <<  to_string(key) << endl;
        // cout << "iv: " << sizeof(*iv) <<   to_string(iv) << endl;

        printCharArray(key);
        printCharArray(iv);

    HFSAT::Utils::OpenSSLCrypto oscObj;
    oscObj.encrypt_EVP_aes_256_gcm_init(key, iv);
    oscObj.decrypt_EVP_aes_256_gcm_init(key, iv);

    cout << "Starting Excryption/Decryption for " << MAX_OP << " times..." << endl;
    for( int iter=0; iter< MAX_OP; iter++){
        unsigned char *msg = r.getRandomStringUnsigned(MSG_LEN);

        //printCharArray(msg);

        //getchar();

        CpuProfiler::getUniqueInstance().startTag("EncryptTime");
        oscObj.aes_encrypt(msg, MSG_LEN);
        CpuProfiler::getUniqueInstance().stopTag("EncryptTime");

        CpuProfiler::getUniqueInstance().startTag("DecryptTime");
        oscObj.aes_decrypt_wrapper();
        CpuProfiler::getUniqueInstance().stopTag("DecryptTime");

	    //std::cout << " Decrypted string: " << oscObj.getDecryptedMsg() << std::endl;

        //if(!strcmp(msg, &(oscObj.getDecryptedMsg()))) cout << iter << ": Plantext mismatch." << endl;
    } 

    CpuProfiler::getUniqueInstance().prepareReportAndDumpToFile();
    return 0;
}
