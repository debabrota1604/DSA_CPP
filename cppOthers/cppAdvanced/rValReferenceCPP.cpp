/*
An rvalue reference is a feature introduced in C++11 that provides a way to bind a reference to a temporary value or an rvalue. It allows you to extend the lifetime of a temporary object, making it possible to efficiently move resources from one object to another without creating unnecessary copies.

In C++, references are typically used to bind to lvalues (modifiable entities with a known memory location). However, there are situations where you want to capture and work with temporary values, such as when implementing move semantics for more efficient resource management.

Rvalue references are denoted by the use of double ampersands (&&) after a type. They are used primarily in the context of move constructors, move assignment operators, and perfect forwarding in functions.

Here's a simple example to illustrate the concept of rvalue references:

*/


#include <iostream>

class MyObject {
public:
    MyObject() {
        std::cout << "Constructor called" << std::endl;
    }

    MyObject(const MyObject& other) {
        std::cout << "Copy constructor called" << std::endl;
    }

    MyObject(MyObject&& other) noexcept {
        std::cout << "Move constructor called" << std::endl;
    }
};

int main() {
    MyObject obj1;
    MyObject obj2 = obj1; // Using copy constructor
    MyObject obj3 = std::move(obj1); // Using move constructor with std::move

    return 0;
}


/*
In this example, the MyObject class has a move constructor that takes an rvalue reference parameter. When std::move(obj1) is used, the move constructor is invoked instead of the copy constructor, allowing efficient transfer of resources from obj1 to obj2.

Rvalue references play a crucial role in enabling move semantics, which is essential for optimizing resource management in C++ programs, such as dynamic memory allocations and deallocations. They are a fundamental concept in modern C++ programming and are often used in conjunction with the Standard Template Library (STL) containers, smart pointers, and other modern C++ features.
*/