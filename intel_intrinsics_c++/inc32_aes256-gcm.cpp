#include<bits/stdc++.h>
#include <smmintrin.h>
using namespace std;


#define REPEAT 0


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


void print_block128_singleLine(std::string title, __m128i value) {
    uint8_t bytes[16];
    _mm_storeu_si128((__m128i*)bytes, value);
    std::cout << title << ": ";
    for (int i = 0; i < 16; ++i) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(bytes[i]) << " ";
    }
    std::cout << std::dec << std::endl;
}

void print_block128_singleLine_m128iOrder(std::string title, __m128i value) {
    uint8_t bytes[16];
    _mm_storeu_si128((__m128i*)bytes, value);
    std::cout << title << ": ";

    // Print bytes in reversed order to reflect the actual byte order in the vector:
    for (int i = 15; i >= 0; --i) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(bytes[i]) << " ";
    }
    std::cout << std::dec << std::endl;
}

// void print_Bytes(__m128i data, int size){
//     std::cout << "Individual bytes (reversed order): ";
//     for (int i = size; i >= 0; --i) {
//         uint8_t byte = _mm_extract_epi8(data, i);
//         std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(byte) << " ";
//     }
//     std::cout << std::endl;
// }

// void reverse_caller(){
//     __m128i data = _mm_set_epi32(0x12345678, 0x9ABCDEF0, 0xFEDCBA98, 0x76543210);
//     print_block128_singleLine_m128iOrder("Before reverse: ", data);
//     print_Bytes(data, 16);

//     // Reverse the bytes
//     __m128i reverseMask = _mm_set_epi8(0x0F, 0x0E, 0x0D, 0x0C, 0x0B, 0x0A, 0x09, 0x08, 0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01, 0x00);

//     // Use shuffle to reverse bytes
//     __m128i reversedData = _mm_shuffle_epi8(data, reverseMask);
//     print_block128_singleLine_m128iOrder("After reverse: ", reversedData);
//     //print_Bytes(reversedData, 16);
// }

// void inc32(__m128i *currentIV) {
//     // Create a mask for the increment operation (0, 0, 0, 1)
//     __m128i incrementMask = _mm_setr_epi32(0, 0, 0, 0x00010000);
//     //__m128i incrementMask = _mm_set_epi32(0x01000000, 0, 0, 0);
//     print_block128_singleLine("incrementMask", incrementMask);

//     // Increment the 32-bit counter in currentIV
//     __m128i incrementedCounter = _mm_add_epi32(*currentIV, incrementMask);
//     print_block128_singleLine("incrementedCounter", incrementedCounter);


//     // Check for carry (overflow) in the least significant 32 bits
//     __m128i carryMask = _mm_cmplt_epi32(incrementedCounter, incrementMask);
//     print_block128_singleLine("carryMask", carryMask);

//     // Apply the carry to the higher 32 bits
//     *currentIV = _mm_add_epi32(*currentIV, _mm_unpackhi_epi64(carryMask, carryMask));
//     print_block128_singleLine("incrementedIV", *currentIV);


//     // Apply the carry to the higher 32 bits
//     // __m128i shiftedCarryMask = _mm_slli_si128(carryMask, 4);  // Shift carry bits to appropriate position
//     // *currentIV = _mm_add_epi32(*currentIV, shiftedCarryMask);
// }

// void increment_last32(__m128i* value) {
//     // Create a mask for the increment operation (0, 0, 0, 1)
//     __m128i incrementMask = _mm_set_epi32(0x01000000, 0, 0, 0);
//     //__m128i incrementMask = _mm_set_epi32(0x11111111, 0, 0, 0);
//     print_block128_singleLine("incrementMask", incrementMask);

//     // Increment the last 32 bits of value
//     *value = _mm_add_epi32(*value, incrementMask);
//     print_block128_singleLine("Post increment", *value);

//     // Check for overflow
//     __m128i overflowMask = _mm_cmplt_epi32(*value, incrementMask);
//     print_block128_singleLine("carryMask", overflowMask);

//     // If overflow occurred, reset the last 32 bits to zero
//     //*value = _mm_andnot_si128(overflowMask, *value);
//     //print_block128_singleLine("Overflow result:", *value);

//     // Apply the carry to the higher 32 bits
//     __m128i shiftedCarryMask = _mm_slli_si128(overflowMask, 4);  // Shift carry bits to appropriate position
//     print_block128_singleLine("shiftedCarryMask", shiftedCarryMask);
//     *value = _mm_add_epi32(*value, shiftedCarryMask);
// }

// void inc32_deb(__m128i* value) {
//     // Step 1: Extract last 32 bits
//     __m128i last32BitsMask = _mm_set_epi32(0xFFFFFFFF, 0, 0, 0);
//     //print_block128_singleLine("last 32 bitmask", last32BitsMask);
//     __m128i last32Bits = _mm_and_si128(*value, last32BitsMask);
//     print_block128_singleLine("last 32 bits", last32Bits);

//     // Step 2: Add 1 to last 32 bits, discard any carry
//     __m128i incrementMask = _mm_set_epi32(0x00010000, 0, 0, 0);
//     last32Bits = _mm_add_epi32(last32Bits, incrementMask);
//     print_block128_singleLine("last 32 bits post inc32", last32Bits);

//     // Step 3: Replace last 32 bits in the input with the updated 32 bits
//     __m128i mask = _mm_set_epi32(0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF);
//     *value = _mm_or_si128(_mm_andnot_si128(mask, *value), last32Bits);
//     print_block128_singleLine("final value", *value);
// }

void print_ia_m128i(string title, __m128i value) {
    uint8_t bytes[16];
    _mm_storeu_si128((__m128i*)bytes, value);

    // Print bytes in reverse order (IA convention):
    std::cout << title << ": " << std::hex;
    for (int i = 15; i >= 0; --i) {
        std::cout << std::setw(2) << std::setfill('0') << static_cast<int>(bytes[i]) << " ";
    }
    std::cout << std::dec << std::endl;
}

void checkDeb(){
    __m128i memory128b, newVar, indexPrint;
    unsigned char *iv_str = hexStringToByteArray("78 5b 54 60 4e 66 72 58 4d 74 62 4c 00 00 00 fe", 16);
    unsigned char *index = hexStringToByteArray("0f 0e 0d 0c 0b 0a 09 08 07 06 05 04 03 02 01 00", 16);
    _mm_storeu_si128(&memory128b, _mm_loadu_si128((__m128i*)iv_str));
    _mm_storeu_si128(&indexPrint, _mm_loadu_si128((__m128i*)index));
    // __m128i SWAP_INDEX_REV = _mm_setr_epi8(7,6,5,4,3,2,1,0,15,14,13,12,11,10,9,8);
    // __m128i SWAP_INDEX = _mm_set_epi8(7,6,5,4,3,2,1,0,15,14,13,12,11,10,9,8);
    //__m128i SWAP_INDEX_REV = _mm_setr_epi8(0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15);
    __m128i SWAP_INDEX = _mm_setr_epi8(0,1,2,3,4,5,6,7,8,9,10,11,15,14,13,12);
    __m128i ONE = _mm_setr_epi32(0,0,0,1);
    newVar = _mm_shuffle_epi8(memory128b, SWAP_INDEX); 

    print_block128_singleLine("init Memory: ", memory128b);
    print_block128_singleLine("Index vrble: ", indexPrint);
    cout << endl;
    print_block128_singleLine("swap index : ", SWAP_INDEX);
    // print_block128_singleLine("swap ind Rv: ", SWAP_INDEX_REV);
    cout << endl;
    print_block128_singleLine("finalMemory: ", newVar);
    print_block128_singleLine("Index vrble: ", indexPrint);
    cout << endl;
    print_block128_singleLine("one as m128: ", ONE);
    newVar = _mm_add_epi32(newVar, ONE);
    print_block128_singleLine("Post Incremnt", newVar);
    newVar = _mm_add_epi32(newVar, ONE);
    print_block128_singleLine("Post Incremnt", newVar);
    newVar = _mm_shuffle_epi8(newVar, SWAP_INDEX); 
    print_block128_singleLine("Post Shuffle:", newVar);
}

void inc32_final(__m128i& memory128b){
    __m128i SWAP_MASK = _mm_setr_epi8(0,1,2,3,4,5,6,7,8,9,10,11,15,14,13,12);
    __m128i MASKED_ONE = _mm_setr_epi32(0,0,0,1);

    //initial counter:
    //print_block128_singleLine("init Memory ", memory128b);

    // Step1: shuffle the last 32bits to add
    memory128b = _mm_shuffle_epi8(memory128b, SWAP_MASK);
    //print_block128_singleLine("Post SwpByte", memory128b);

    // Step2: Add 1 to the number
    memory128b = _mm_add_epi32(memory128b, MASKED_ONE);
    //print_block128_singleLine("Post Incrmnt", memory128b);

    // Step3: restore the swap to get the original data
    memory128b = _mm_shuffle_epi8(memory128b, SWAP_MASK); 
    print_block128_singleLine("Post Shuffle", memory128b);
}

void inc32_minimal(__m128i& memory128b){
    __m128i SWAP_MASK = _mm_setr_epi8(0,1,2,3,4,5,6,7,8,9,10,11,15,14,13,12);
    memory128b = _mm_shuffle_epi8(_mm_add_epi32(_mm_shuffle_epi8(memory128b, SWAP_MASK), _mm_setr_epi32(0,0,0,1)), SWAP_MASK); 
    print_block128_singleLine("Post Shuffle", memory128b);
}

int main(){

     // create an 128 bit intrinsic var and load the candidate
    __m128i memory128b;
    unsigned char *iv_str;
    //candidate = r.hexStringToByteArray("50 62 53 52 64 51 5b 6d 71 63 78 77 5e 7a 51 00 50 62 53 52 64 51 5b 6d 71 63 78 77 5e 7a 51 00", AES_INPUT_SIZE);
    iv_str = hexStringToByteArray("78 5b 54 60 4e 66 72 58 4d 74 62 4c 00 00 00 01", 16);
    _mm_storeu_si128(&memory128b, _mm_loadu_si128((__m128i*)iv_str));
    while(1) inc32_minimal(memory128b);
    
//     __m128i ctr_block, tmp, ONE, BSWAP_EPI64; 
//     int i,j;

//     ONE = _mm_set_epi32(0,1,0,0);
//     BSWAP_EPI64 = _mm_setr_epi8(7,6,5,4,3,2,1,0,15,14,13,12,11,10,9,8);

//     //ctr_block = _mm_insert_epi64(ctr_block, *(long long*)iv, 1); 
//     //ctr_block = _mm_insert_epi32(ctr_block, *(long*)nonce, 1); 
//     ctr_block = _mm_srli_si128(memory128b, 4);
//     ctr_block = _mm_shuffle_epi8(ctr_block, BSWAP_EPI64); 
//     ctr_block = _mm_add_epi64(ctr_block, ONE);
//     for(i=0; i < length; i++){
//         tmp = _mm_shuffle_epi8(ctr_block, BSWAP_EPI64); 
//         ctr_block = _mm_add_epi64(ctr_block, ONE);
//         tmp = _mm_xor_si128(tmp, ((__m128i*)key)[0]);
//         for(j=1; j <number_of_rounds; j++) {
//             tmp = _mm_aesenc_si128 (tmp, ((__m128i*)key)[j]); 
//         }
//         tmp = _mm_aesenclast_si128 (tmp, ((__m128i*)key)[j]);
//         tmp = _mm_xor_si128(tmp,_mm_loadu_si128(&((__m128i*)in)[i])); 
//         _mm_storeu_si128 (&((__m128i*)out)[i],tmp);
//     } 
// }





    //_mm_storeu_si128(&memory128b, _mm_loadu_si128((__m128i*)candidate));

    // print_block128_singleLine("Initial Counter: ", memory128b);
    // for(int iter=0; iter<REPEAT; iter++){
    //     inc32_deb(&memory128b);
    //     print_block128_singleLine("Iter" + to_string(iter) + " Counter", memory128b);
    //     std::cout << std::endl;
    // }
}