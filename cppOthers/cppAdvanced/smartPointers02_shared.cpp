
/*
std::shared_ptr: This smart pointer represents shared ownership of an object. Multiple std::shared_ptr instances can point to the same object. The object is deleted only when the last std::shared_ptr that owns it is destructed or reset.
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
    // Using shared_ptr
    std::shared_ptr<MyClass> sharedPtr1 = std::make_shared<MyClass>();

    // Creating another shared_ptr pointing to the same object
    std::shared_ptr<MyClass> sharedPtr2 = sharedPtr1;

    // Accessing member function
    sharedPtr1->SomeFunction();
    sharedPtr2->SomeFunction();

    // The memory is automatically released when the last shared_ptr pointing to the object is destroyed
    return 0;
}

