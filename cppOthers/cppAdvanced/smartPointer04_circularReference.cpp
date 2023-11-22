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
    std::shared_ptr<A> a_ptr;

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

    // Creating a circular reference
    a->b_ptr = b;
    b->a_ptr = a;

    return 0;
}

//In this example, A and B both have shared_ptr members pointing to each other, creating a circular reference.