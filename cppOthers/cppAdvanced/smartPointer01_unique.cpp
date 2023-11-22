
/*
std::unique_ptr: This smart pointer represents exclusive ownership of an object. Only one std::unique_ptr can point to a particular object at a time. When the std::unique_ptr goes out of scope or is explicitly deleted, it automatically deallocates the memory associated with the object it owns.s
*/

#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass() {
        std::cout << "MyClass Constructor\n";
    }

    ~MyClass() {
        std::cout << "MyClass Destructor\n";
    }

    void SomeFunction() {
        std::cout << "SomeFunction called\n";
    }
};

int main() {
    // Using unique_ptr
    std::unique_ptr<MyClass> uniquePtr(new MyClass);

    // Accessing member function
    uniquePtr->SomeFunction();

    // unique_ptr automatically releases memory when it goes out of scope
    return 0;
}

