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