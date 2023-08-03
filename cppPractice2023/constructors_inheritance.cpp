#include <iostream>

class A
{
public:
        A() { initialize(); }
        virtual void initialize() { std::cout << "A::initialize()" << std::endl; }
};

class B : public A {
public:
        virtual void initialize() { std::cout << "B::initialize()" << std::endl; }
};

int main() {
        B b;
        return 0;
}