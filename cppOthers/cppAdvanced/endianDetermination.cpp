#include <iostream>

bool isBigEndian() {
    int num = 1;
    char* byte = reinterpret_cast<char*>(&num);
    return (byte[0] == 0);
}

int main() {
    if (isBigEndian()) {
        std::cout << "Big endian" << std::endl;
    } else {
        std::cout << "Little endian" << std::endl;
    }
    
    return 0;
}


/*

C program: multiply two 32 bit value & return in 64-bit on a processor having a 16*16 multiplier.
Answer: Let's call the 32 bit numbers A and B. Now, let's split them into 16 bit numbers, a0/b0 and a1/b1 (a0 is the bigger part).
Now, A*B == (a0<<16+a1) * (b0<<16+b1) == (a0 * b0) << 32 + (a1 * b0 + a0 * b1) << 16 + a1 * b1.

note: All the multiplications here are for 16 bit numbers (a0,a1,b0,b1) with the result as 32 bit number casted into 64 bit (the bigger 32 bits of the number are 0).

Use the above code to determine endianness and split the 32 bit numbers.
*/