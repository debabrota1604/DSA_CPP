#include <iostream>

// Define a volatile hardware register as a pointer to an int
volatile int* hardwareRegister = reinterpret_cast<volatile int*>(0x12345678); // Memory address of the hardware register

int main() {
    // Read the value from the hardware register
    int value = *hardwareRegister;

    //Gives seg fault in modern systems
    std::cout << "Value from hardware register: " << value << std::endl;

    // Perform some operations
    value *= 2;

    // Write a new value to the hardware register
    *hardwareRegister = value;

    return 0;
}
