#include <memory>
#include <iostream>

class B;  // Forward declaration

class A {
public:
    std::shared_ptr<B> b_ptr;

    A() {
        std::cout << "A constructor\n";
    }

    ~A() {
        std::cout << "A destructor\n";
    }
};

class B {
public:
    std::weak_ptr<A> a_ptr;  // Use weak_ptr instead of shared_ptr

    B() {
        std::cout << "B constructor\n";
    }

    ~B() {
        std::cout << "B destructor\n";
    }
};

int main() {
    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>();

    // Creating a circular reference with weak_ptr
    a->b_ptr = b;
    b->a_ptr = a;

    // Note: No explicit reset is needed, weak_ptr doesn't affect the reference count

    return 0;
}

/*
By using std::weak_ptr for the circular link, you break the strong ownership and prevent the circular reference from keeping the objects alive indefinitely. This allows the objects to be properly destructed when the last shared_ptr pointing to them goes out of scope.
*/