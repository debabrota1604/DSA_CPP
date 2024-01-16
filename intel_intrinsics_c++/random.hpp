
// This code was written by Debabrota Sadhukhan. Kindly contact for any queries.
#include <bits/stdc++.h>
#include <sstream>
#include <iomanip>
using namespace std;

#ifndef __time_t_defined
#define __time_t_defined 1

/* Returned by `time'.  */
typedef __time_t time_t;

#endif

class RandomNumC{
    time_t t;
    public:
    RandomNumC(){ srand((unsigned) time(&t)); }
    double getRandomDouble(){ return ((unsigned long) rand() * UINT64_MAX); }
    int64_t getRandomInt64(){ return ((int64_t) rand() * INT64_MAX); }
    uint64_t getRandomUInt64(){ return ((uint64_t) rand() * UINT64_MAX); }
    uint32_t getRandomUInt32(){ return ((uint32_t) rand() * UINT32_MAX); }
    int32_t getRandomInt32(){ return ((int32_t) rand() * INT32_MAX); }
    int getRandomInt(){ return ((int) rand() * INT_MAX); }
    char getRandomChar(){ return ((char) rand() %26 + 'a'); }
    bool getRandomBool(){ return ((bool) rand() * 2); }
    char* getRandomString(int size) {
        char* arr = new char[size];
        for (int iter = 0; iter < size - 1; iter++) {
            arr[iter] = getRandomChar();
        }
        arr[size - 1] = '\0';
        return arr;
    }

    unsigned char* getRandomStringUnsigned(int size) {
        unsigned char* arr = new unsigned char[size];
        for (int iter = 0; iter < size - 1; iter++) {
            arr[iter] = static_cast<unsigned char>(getRandomChar());
        }
        arr[size - 1] = '\0'; //NULL Padded
        return arr;
    }

    uint8_t* getRandomUint8(int size) { // No null padding
        uint8_t* arr = new uint8_t[size];
        for (int iter = 0; iter < size; iter++) {
            arr[iter] = static_cast<uint8_t>(getRandomChar());
        }
        return arr;
    }

    void print_uint8_Array(const uint8_t *inp, int size){
        unsigned long leng=0;
        for(int iter=0; iter<size;iter++){
            printf("%d ", inp[iter]);
        }
        std::cout << std::dec << std::endl;
    }

    void print_uint8_Array_hex(const uint8_t* inp, int size) {
        for (int iter = 0; iter < size; ++iter) {
            if(iter>0 && iter%16 ==0) std::cout << "\n\t";
            std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(inp[iter]) << " ";

        }
        std::cout << std::dec << std::endl;
    }
    
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

};
