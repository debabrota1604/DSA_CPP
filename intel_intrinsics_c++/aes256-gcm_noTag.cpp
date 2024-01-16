#include <wmmintrin.h>
#include <cstdint>
#include <iostream>
#include <smmintrin.h>
#include <iomanip>  // Include this header for setw and setfill


class AES256_GCM_NoTag{    
    public:
        // Optimized code: Needs to be verified
    // [[nodiscard]] static __m128i aes_expand_key_step(__m128i key0, __m128i key1, int round_const) noexcept {
    //     key0 = _mm_xor_si128(key0, _mm_slli_si128(key0, 4));
    //     key0 = _mm_xor_si128(key0, _mm_slli_si128(key0, 4));
    //     key0 = _mm_xor_si128(key0, _mm_slli_si128(key0, 4));
    //     return _mm_xor_si128(key0, _mm_shuffle_epi32(key1, 0xff));
    // }

    // void AES_256_Key_Expansion(const uint8_t key[32], __m128i this->key_schedule[15]) noexcept {
    //     this->key_schedule[0] = _mm_loadu_si128(reinterpret_cast<const __m128i*>(&key[0]));
    //     this->key_schedule[1] = _mm_loadu_si128(reinterpret_cast<const __m128i*>(&key[16]));

    //     for (int i = 2; i < 15; i++) {
    //         this->key_schedule[i] = aes_expand_key_step(this->key_schedule[i - 2], _mm_aeskeygenassist_si128(this->key_schedule[i - 1], i&1 ?  0x01 : 0),  // Use i % 2 for round constant
    //                                                                                                                   i&1 ? 0xaa:0xff); // Adjust shuffle constant based on round
    //     }
    // }

    // void load_iv_96(uint8_t* iv_96b) { //uses __m128i directly
    //     counter_block = (__m128i*)_mm_malloc(sizeof(__m128i), 16);
    //     // Load the original 96-bit IV into a 128-bit register
    //     __m128i iv_128b = _mm_loadu_si128((__m128i*)iv_96b);

    //     // Store the first 128 bits (the original IV) into extendedIV_128b
    //     _mm_storeu_si128(counter_block, iv_128b);

    //     // Fill the next 128 bits with zeros
    //     counter_block[1] = _mm_setzero_si128();

    //     // Set the last byte of the extended IV to 0x01
    //     counter_block[1][15] = 0x01;
    //     print_m128i(*(this->counter_block));
    // }

    // void load_iv_96(uint8_t* iv_96b) { //reduces intermediate variable
    //     counter_block = (__m128i*)_mm_malloc(sizeof(__m128i), 16);
    //     // Load the original 96-bit IV directly into the first 128-bit block,
    //     // avoiding an extra register and store operation
    //     _mm_storeu_si128(this->counter_block, _mm_loadu_si128((__m128i*)iv_96b));


    //     // Combine zeroing and setting the last byte in a single instruction
    //     counter_block[1] = _mm_insert_epi8(_mm_setzero_si128(), 0x01, 15);
    //     //print_m128i(*(this->counter_block));
    // }

    // Stores all round keys
    __m128i key_schedule[15], key_schedule_decrypt[15];

    // Expand the IV to a 128-bit block
    __m128i *counter_block_enc, *counter_block_dec;



    AES256_GCM_NoTag(){
        this->counter_block_enc = nullptr;
        this->counter_block_dec = nullptr;
    }
    ~AES256_GCM_NoTag(){
        // Free the allocated memory
        if (this->counter_block_enc) _mm_free(this->counter_block_enc);
        if (this->counter_block_dec) _mm_free(this->counter_block_dec);
    }

    void initialize(const uint8_t* key,  uint8_t* iv){
        load_key_256(key);
        load_key_256_decrypt();
        load_iv_96(iv);
    }

    [[nodiscard]] static __m128i aes_expand_key_evn_step(__m128i key0, __m128i key1) noexcept
    {
        key0 = _mm_xor_si128(key0, _mm_slli_si128(key0, 4));
        key0 = _mm_xor_si128(key0, _mm_slli_si128(key0, 4));
        key0 = _mm_xor_si128(key0, _mm_slli_si128(key0, 4));
        return _mm_xor_si128(key0, _mm_shuffle_epi32(key1, 0xff));
    }

    [[nodiscard]] static __m128i aes_expand_key_odd_step(__m128i key0, __m128i key1) noexcept
    {
        key0 = _mm_aeskeygenassist_si128(key0, 0);
        key1 = _mm_xor_si128(key1, _mm_slli_si128(key1, 4));
        key1 = _mm_xor_si128(key1, _mm_slli_si128(key1, 4));
        key1 = _mm_xor_si128(key1, _mm_slli_si128(key1, 4));
        return _mm_xor_si128(key1, _mm_shuffle_epi32(key0, 0xaa));
    }    

    void print_m128i(__m128i value) {
        std::cout<< "Printing 128bit register value: ";
        uint8_t bytes[16];
        _mm_storeu_si128((__m128i*)bytes, value);

        for (int i = 0; i < 16; ++i) {
            std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(bytes[i]);
        }
        std::cout << std::endl;
    }

    void print_all_keys(){
        for(int iter=0; iter<15; iter++){
            std::string temp = "Round Key " + std::to_string(iter);
            print_aes_block(temp, this->key_schedule[iter]);
        }
    }

    void print_aes_block(std::string title, __m128i value) {
        uint8_t bytes[16];
        _mm_storeu_si128((__m128i*)bytes, value);

        std::cout << title << std::endl;

        for (int j = 0; j < 4; ++j) {
            for (int i = 0; i < 4; ++i) {
                int index = i * 4 + j;
                std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(bytes[index]) << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    void print_aes_block_singleLine(std::string title, __m128i value) {
        uint8_t bytes[16];
        _mm_storeu_si128((__m128i*)bytes, value);

        std::cout << title << std::endl;

        for (int i = 0; i < 16; ++i) {
            std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(bytes[i]) << " ";
        }
        std::cout << std::endl << std::endl;
    }

    // void load_key_256(const uint8_t key[32]) noexcept //optimized code, not tested
    // {
    //     this->key_schedule[0] = _mm_loadu_si128(reinterpret_cast<const __m128i*>(&key[0]));
    //     this->key_schedule[1] = _mm_loadu_si128(reinterpret_cast<const __m128i*>(&key[16]));

    //     for (int i = 2; i < 14; i += 2){
    //         this->key_schedule[i] = aes_expand_key_evn_step(this->key_schedule[i - 2], _mm_aeskeygenassist_si128(this->key_schedule[i - 1], 0x01));
    //         this->key_schedule[i + 1] = aes_expand_key_odd_step(this->key_schedule[i], this->key_schedule[i - 1]);
    //     }
    // }

    void load_key_256(const uint8_t key[32]) noexcept
	{
		this->key_schedule[0] = _mm_loadu_si128(&reinterpret_cast<const __m128i*>(key)[0]);
		this->key_schedule[1] = _mm_loadu_si128(&reinterpret_cast<const __m128i*>(key)[1]);
		this->key_schedule[2] = aes_expand_key_evn_step(this->key_schedule[0], _mm_aeskeygenassist_si128(this->key_schedule[1], 0x01));
		this->key_schedule[3] = aes_expand_key_odd_step(this->key_schedule[2], this->key_schedule[1]);
		this->key_schedule[4] = aes_expand_key_evn_step(this->key_schedule[2], _mm_aeskeygenassist_si128(this->key_schedule[3], 0x02));
		this->key_schedule[5] = aes_expand_key_odd_step(this->key_schedule[4], this->key_schedule[3]);
		this->key_schedule[6] = aes_expand_key_evn_step(this->key_schedule[4], _mm_aeskeygenassist_si128(this->key_schedule[5], 0x04));
		this->key_schedule[7] = aes_expand_key_odd_step(this->key_schedule[6], this->key_schedule[5]);
		this->key_schedule[8] = aes_expand_key_evn_step(this->key_schedule[6], _mm_aeskeygenassist_si128(this->key_schedule[7], 0x08));
		this->key_schedule[9] = aes_expand_key_odd_step(this->key_schedule[8], this->key_schedule[7]);
		this->key_schedule[10] = aes_expand_key_evn_step(this->key_schedule[8], _mm_aeskeygenassist_si128(this->key_schedule[9], 0x10));
		this->key_schedule[11] = aes_expand_key_odd_step(this->key_schedule[10], this->key_schedule[9]);
		this->key_schedule[12] = aes_expand_key_evn_step(this->key_schedule[10], _mm_aeskeygenassist_si128(this->key_schedule[11], 0x20));
		this->key_schedule[13] = aes_expand_key_odd_step(this->key_schedule[12], this->key_schedule[11]);
		this->key_schedule[14] = aes_expand_key_evn_step(this->key_schedule[12], _mm_aeskeygenassist_si128(this->key_schedule[13], 0x40));
	}
    void load_key_256_decrypt() noexcept
	{
		this->key_schedule_decrypt[14] = this->key_schedule[0];
		this->key_schedule_decrypt[13] = _mm_aesimc_si128(this->key_schedule[1]);
		this->key_schedule_decrypt[12] = _mm_aesimc_si128(this->key_schedule[2]);
		this->key_schedule_decrypt[11] = _mm_aesimc_si128(this->key_schedule[3]);
		this->key_schedule_decrypt[10] = _mm_aesimc_si128(this->key_schedule[4]);
		this->key_schedule_decrypt[9] = _mm_aesimc_si128(this->key_schedule[5]);
		this->key_schedule_decrypt[8] = _mm_aesimc_si128(this->key_schedule[6]);
		this->key_schedule_decrypt[7] = _mm_aesimc_si128(this->key_schedule[7]);
		this->key_schedule_decrypt[6] = _mm_aesimc_si128(this->key_schedule[8]);
		this->key_schedule_decrypt[5] = _mm_aesimc_si128(this->key_schedule[9]);
		this->key_schedule_decrypt[4] = _mm_aesimc_si128(this->key_schedule[10]);
		this->key_schedule_decrypt[3] = _mm_aesimc_si128(this->key_schedule[11]);
		this->key_schedule_decrypt[2] = _mm_aesimc_si128(this->key_schedule[12]);
		this->key_schedule_decrypt[1] = _mm_aesimc_si128(this->key_schedule[13]);
		this->key_schedule_decrypt[0] = this->key_schedule[14];
	}

    void load_iv_96(uint8_t* iv_96b) { //reduces intermediate variable
        counter_block_enc = (__m128i*)_mm_malloc(sizeof(__m128i), 16);
        counter_block_dec = (__m128i*)_mm_malloc(sizeof(__m128i), 16);
        // Load the original 96-bit IV directly into the first 128-bit block,
        // avoiding an extra register and store operation
        _mm_storeu_si128(this->counter_block_enc, _mm_loadu_si128((__m128i*)iv_96b));

        // Combine zeroing and setting the last byte in a single instruction, then bitwise-OR
        *counter_block_enc = _mm_insert_epi8(*counter_block_enc, 0x01, 15);
        *counter_block_dec = *counter_block_enc; //copy iv
        //print_m128i(*(this->counter_block_enc));
        //print_aes_block("IV as AES block", *(this->counter_block_enc));
    }

    void aes_gcm_encrypt(uint8_t* plaintext, size_t plaintext_len, uint8_t* ciphertext) {
        // Encrypt plaintext blocks
        for (size_t i = 0; i < plaintext_len; i += 16) {
            __m128i encrypted_counter_block;
            // print_aes_block("plain IV before Inc32", *counter_block_enc);
            //print_aes_block_singleLine("plain IV before Inc32", *counter_block_enc);
            // *counter_block_enc = _mm_add_epi64(*counter_block_enc, _mm_set_epi64x(0, 1));
            inc32_minimal(counter_block_enc);

            //print_aes_block_singleLine("Updated IV:    ", temp);
            // print_aes_block("plain IV at Enc", *counter_block_enc);
            encrypt_iv(counter_block_enc, &encrypted_counter_block);
            // print_aes_block("encrypted IV at Enc", encrypted_counter_block);


            // XOR plaintext with the encrypted counter block
            __m128i input_block = _mm_loadu_si128(reinterpret_cast<__m128i*>(plaintext + i));
            __m128i ciphertext_block = _mm_xor_si128(input_block, encrypted_counter_block);
            _mm_storeu_si128((__m128i*)(ciphertext + i), ciphertext_block);

            // print_aes_block("input_block at Enc", input_block);
            // print_aes_block("Xor output frm Enc", ciphertext_block);
        }
        if(plaintext_len %16 !=0) dec32_minimal(counter_block_enc);
    }

    
    void aes_gcm_decrypt(uint8_t* ciphertext, size_t ciphertext_len, uint8_t* plaintext) {
        // Decrypt ciphertext blocks
        if(ciphertext_len %16 !=0) dec32_minimal(counter_block_enc);
        for (size_t i = 0; i < ciphertext_len; i += 16) {
            __m128i encrypted_counter_block;
            inc32_minimal(counter_block_dec);
            // print_aes_block("plain IV at Dec", *counter_block_dec);
            encrypt_iv(counter_block_dec, &encrypted_counter_block);
            // print_aes_block("encrypted IV at Dec", encrypted_counter_block);    


            // XOR ciphertext with the encrypted counter block to obtain the plaintext
            __m128i ciphertext_block = _mm_loadu_si128(reinterpret_cast<__m128i*>(ciphertext + i));
            __m128i plaintext_block = _mm_xor_si128(ciphertext_block, encrypted_counter_block);
            _mm_storeu_si128((__m128i*)(plaintext + i), plaintext_block);

            // print_aes_block("input_block at Dec", ciphertext_block);
            // print_aes_block("Xor output frm Dec", plaintext_block);
        }
    }

    // void inc32_depricated(__m128i currentIV, __m128i* incrementedIV) { // For experiments
    //     //print_aes_block("Inside inc32 Initial IV", currentIV);
    //     // Create a mask with the lowest 32 bits set to 0xFFFFFFFF
    //     const __m128i mask = _mm_setr_epi32(0, 0, 0, 0xFFFFFFFF);
    //     //print_aes_block("Inside inc32 Initial Mask", mask);

    //     // Isolate the last 32 bits and increment them directly within the register
    //     __m128i tempInt, lastInt = _mm_and_si128(currentIV, mask);
    //     //print_aes_block("Inside inc32 After Mask", lastInt);
    //     tempInt = _mm_setr_epi32(0, 0, 0, 0x01000000);
    //     //print_aes_block("Inside inc32 TempInt:Incr", tempInt);
    //     lastInt = _mm_add_epi32(lastInt, tempInt);
    //     //print_aes_block("Inside inc32 LastInt:ADD", lastInt);

    //     // Blend the incremented value back into the original IV
    //     *incrementedIV = _mm_blendv_epi8(currentIV, lastInt, mask); //FLAGS: SSE4.1

    //     //print_aes_block("Inside inc32 Final", *incrementedIV);
    // }

    // void inc32(const __m128i currentIV, __m128i* incrementedIV) {
    //     // Create a mask for the increment operation (0, 0, 0, 1)
    //     __m128i incrementMask = _mm_set_epi32(0x1000000, 0, 0, 0);
    //     print_aes_block_singleLine("incrementMask", incrementMask);

    //     // Increment the 32-bit counter in currentIV
    //     __m128i incrementedCounter = _mm_add_epi32(currentIV, incrementMask);
    //     print_aes_block_singleLine("incrementedCounter", incrementedCounter);


    //     // Check for carry (overflow) in the least significant 32 bits
    //     __m128i carryMask = _mm_cmplt_epi32(incrementedCounter, incrementMask);
    //     print_aes_block_singleLine("carryMask", carryMask);

    //     // Apply the carry to the higher 32 bits
    //     *incrementedIV = _mm_add_epi32(currentIV, _mm_unpackhi_epi64(carryMask, carryMask));
    //     print_aes_block_singleLine("incrementedIV", *incrementedIV);
    // }

    // void inc32_single_deprecated(const __m128i currentIV, __m128i* incrementedIV) { //Single call for inc32 increment, optimized
    //     // Increment the last 32 bits of currentIV by 1
    //     *incrementedIV = _mm_add_epi32(currentIV, _mm_setr_epi32(0, 0, 0, 0x01000000));
    // }

    // void inc32_single(const __m128i currentIV, __m128i* incrementedIV) {
    //     // Increment the last 32 bits of currentIV by 1
    //     *incrementedIV = _mm_add_epi32(currentIV, _mm_set_epi32(0, 0, 0, 1));
    // }

    void inc32_minimal(__m128i* memory128b){
        __m128i SWAP_MASK = _mm_setr_epi8(0,1,2,3,4,5,6,7,8,9,10,11,15,14,13,12);
        *memory128b = _mm_shuffle_epi8(_mm_add_epi32(_mm_shuffle_epi8(*memory128b, SWAP_MASK), _mm_setr_epi32(0,0,0,1)), SWAP_MASK); 
    }
    void dec32_minimal(__m128i* memory128b){
        __m128i SWAP_MASK = _mm_setr_epi8(0,1,2,3,4,5,6,7,8,9,10,11,15,14,13,12);
        *memory128b = _mm_shuffle_epi8(_mm_sub_epi32(_mm_shuffle_epi8(*memory128b, SWAP_MASK), _mm_setr_epi32(0,0,0,1)), SWAP_MASK); 
    }

    void inc32_minimal_bardOptimized(__m128i& memory128b) {
        // Pre-calculate and store the SWAP_MASK for efficiency:
        static const __m128i SWAP_MASK = _mm_setr_epi8(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 15, 14, 13, 12);

        // Optimized using _mm_add_epi64 and _mm_shuffle_epi32:
        memory128b = _mm_shuffle_epi32(_mm_add_epi64(memory128b, _mm_set_epi64x(0, 1)), _MM_SHUFFLE(2, 3, 0, 1));

        //print_aes_block_singleLine("Post Shuffle", memory128b);
    }

    // For single block encrypt using AES
	void encrypt_iv(const __m128i* plaintext, __m128i* ciphertext) noexcept
	{
        // print_aes_block("Before Encryption Round 0", *plaintext);
        // print_aes_block("Key at Round 0", key_schedule[0]);
        *ciphertext = _mm_xor_si128(*plaintext, key_schedule[0]);
        //print_aes_block("After Encryption Round 0", *ciphertext);
        for(auto iter=1; iter<14; iter++){
            *ciphertext = _mm_aesenc_si128(*ciphertext, key_schedule[iter]);
            //print_aes_block("After Encryption Round " + std::to_string(iter), *ciphertext);
        }

		*ciphertext = _mm_aesenclast_si128(*ciphertext, key_schedule[14]);
        //print_aes_block("After Encryption Round 14", *ciphertext);
	}

    // For single block decrypt using AES
    void decrypt_iv( __m128i* ciphertext, __m128i* plaintext) noexcept
    {
        // print_aes_block("Before Decryption Round 14", *ciphertext);
        // print_aes_block("Key at Round 14", key_schedule_decrypt[0]);
        *plaintext = _mm_xor_si128(*ciphertext, key_schedule_decrypt[0]);
        // print_aes_block("After Decryption Round 14", *plaintext);

        for (auto iter = 1; iter < 14; iter++) {
            *plaintext = _mm_aesdec_si128(*plaintext, key_schedule_decrypt[iter]);
            // print_aes_block("After Decryption Round " + std::to_string(iter), *plaintext);
        }

        *plaintext = _mm_aesdeclast_si128(*plaintext, key_schedule_decrypt[14]);
        // print_aes_block("After Decryption Round 0", *plaintext);
    }

    void encrypt_iv_2(const __m128i* plaintext, __m128i* ciphertext) noexcept //matched encryption with openssl
	{

        int number_of_rounds = 14; int j;
        __m128i tmp = _mm_loadu_si128 (plaintext); 
        tmp = _mm_xor_si128 (tmp,((__m128i*)key_schedule)[0]); 
        for(j=1; j <number_of_rounds; j++){
            tmp = _mm_aesenc_si128 (tmp,((__m128i*)key_schedule)[j]); 
        }
        tmp = _mm_aesenclast_si128 (tmp,((__m128i*)key_schedule)[j]); 
        _mm_storeu_si128 (ciphertext,tmp);
	}

    void decrypt_iv_2(const __m128i* ciphertext, __m128i* plaintext) noexcept //matched decryption with openssl
    {
        int number_of_rounds = 14; int j;
        __m128i tmp = _mm_loadu_si128 (ciphertext); 
        tmp = _mm_xor_si128 (tmp,((__m128i*)key_schedule_decrypt)[0]); 
        for(j=1; j <number_of_rounds; j++){
            tmp = _mm_aesdec_si128 (tmp,((__m128i*)key_schedule_decrypt)[j]); 
        }
        tmp = _mm_aesdeclast_si128 (tmp,((__m128i*)key_schedule_decrypt)[j]); 
        _mm_storeu_si128 (plaintext,tmp);
    }


};