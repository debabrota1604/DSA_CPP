#include <iostream>

/*
const_cast is a type of C++ casting operator used to add or remove the const qualifier from a pointer or reference. It is often used when you have a pointer or reference to a const object and need to perform operations that modify the object. Keep in mind that using const_cast to remove the const qualifier and modify a truly const object results in undefined behavior.
*/

int main() {
    const int x = 5;

    // Using const_cast to remove const qualifier
    int* nonConstPtr = const_cast<int*>(&x);

    // Modifying the value through the non-const pointer
    *nonConstPtr = 10;

    // Note: Modifying a const object is undefined behavior!
    // The above line results in undefined behavior.

    // Printing the modified value
    std::cout << "Modified value: " << x << std::endl;

    return 0;
}


/*
In this example, we have a const integer x, and we use const_cast to create a non-const pointer nonConstPtr. Then, we attempt to modify the value pointed to by nonConstPtr. However, keep in mind that modifying a const object in this way results in undefined behavior.

It's important to use const_cast judiciously and be aware of the implications, as improper usage can lead to unexpected and undefined behavior in your program.
*/