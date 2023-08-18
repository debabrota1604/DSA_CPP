#include <memory>

/*
std::shared_ptr: This smart pointer represents shared ownership 
of an object. Multiple std::shared_ptr instances can point to the same object.
The object is deleted only when the last std::shared_ptr that owns it is destructed or reset.
*/

int main() {
    std::shared_ptr<int> ptr1 = std::make_shared<int>(42);
    std::shared_ptr<int> ptr2 = ptr1; // Both ptr1 and ptr2 share ownership of the same integer

    return 0;
} // The memory is automatically deallocated when the last shared_ptr (ptr2) goes out of scope or is reset
