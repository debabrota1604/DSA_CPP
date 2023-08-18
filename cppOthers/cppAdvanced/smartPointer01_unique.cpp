#include <memory>

/*
std::unique_ptr: This smart pointer represents exclusive ownership of an object. 
Only one std::unique_ptr can point to a particular object at a time. When the 
std::unique_ptr goes out of scope or is explicitly deleted, it automatically 
deallocates the memory associated with the object it owns.

*/



int main() {
    std::unique_ptr<int> ptr = std::make_unique<int>(42);
    // ptr owns the memory allocated for the integer 42

    return 0;
} // The memory is automatically deallocated when ptr goes out of scope
