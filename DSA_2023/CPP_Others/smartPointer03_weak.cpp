#include <memory>

/*
std::weak_ptr: This smart pointer is used in conjunction with std::shared_ptr. 
It provides a non-owning, weak reference to an object. It does not contribute 
to the reference count of the object, and it does not prevent the object from 
being deleted. It is useful to avoid circular reference issues when using std::shared_ptr.

*/


int main() {
    std::shared_ptr<int> sharedPtr = std::make_shared<int>(42);
    std::weak_ptr<int> weakPtr = sharedPtr;

    // Use weakPtr
    if (auto ptr = weakPtr.lock()) {
        // The object is still valid
    } else {
        // The object has been deleted
    }

    return 0;
}
