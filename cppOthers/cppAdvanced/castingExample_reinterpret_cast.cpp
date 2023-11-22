#include <iostream>

/*
reinterpret_cast is a type of casting operator in C++ that is used for low-level casting between pointer types and integral types. It can perform conversions that would be considered unsafe or implementation-dependent by other casting operators.

Here's an example illustrating the use of reinterpret_cast:
*/


int main() {
    // Example 1: Casting between pointer types
    int x = 10;
    int* ptr = &x;

    // Using reinterpret_cast to cast from int* to void*
    void* voidPtr = reinterpret_cast<void*>(ptr);

    // Using reinterpret_cast to cast back from void* to int*
    int* originalPtr = reinterpret_cast<int*>(voidPtr);

    // Example 2: Casting between pointer and integral types
    long longValue = 123456789012345;

    // Using reinterpret_cast to cast from long to int*
    int* intPtr = reinterpret_cast<int*>(&longValue);

    // Using reinterpret_cast to cast back from int* to long
    long originalLongValue = reinterpret_cast<long>(intPtr);

    // Printing results
    std::cout << "Original value: " << *originalPtr << std::endl;
    std::cout << "Original long value: " << originalLongValue << std::endl;

    return 0;
}

/*
In Example 1, reinterpret_cast is used to convert between a pointer to int and a pointer to void and back. In Example 2, it is used to reinterpret a long value as a pointer to int and back. These examples demonstrate how reinterpret_cast can be used for low-level casting but should be used with caution, as it can lead to undefined behavior if misused. Always make sure that the conversion makes sense in the context of your program and that you understand the potential risks involved.
*/
