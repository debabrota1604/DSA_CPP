#include <iostream>
#include <stdint.h>

int main() {
    uint32_t value = 0x12345678;
    uint8_t* bytes = (uint8_t*)&value;

    if (bytes[0] == 0x78) {
        std::cout << "System is little-endian." << std::endl;
    } else if (bytes[0] == 0x12) {
        std::cout << "System is big-endian." << std::endl;
    } else {
        std::cout << "Unknown endianness." << std::endl;
    }

    return 0;
}

