#include <iostream>

class Base {
public:
    int publicVar;

    Base() : publicVar(0) {}

    void publicMethod() {
        std::cout << "Public Method in Base" << std::endl;
    }

private:
    int privateVar;

    void privateMethod() {
        std::cout << "Private Method in Base" << std::endl;
    }

protected:
    int protectedVar;

    void protectedMethod() {
        std::cout << "Protected Method in Base" << std::endl;
    }
};

class Derived : public Base {
public:
    void accessBaseMembers() {
        publicVar = 10;         // Accessible (public)
        publicMethod();         // Accessible (public)

        // privateVar = 20;     // Not accessible (private)
        // privateMethod();     // Not accessible (private)

        protectedVar = 30;      // Accessible (protected)
        protectedMethod();      // Accessible (protected)
    }
};

int main() {
    Derived derivedObj;
    derivedObj.accessBaseMembers(); // Accessing protected members through derived class

    // derivedObj.publicVar = 5;    // Accessible (public) through inheritance
    // derivedObj.publicMethod();   // Accessible (public) through inheritance

    // derivedObj.privateVar = 15;  // Not accessible (private)
    // derivedObj.privateMethod();  // Not accessible (private)

    // derivedObj.protectedVar = 25; // Not accessible (protected)
    // derivedObj.protectedMethod(); // Not accessible (protected)

    return 0;
}

/*
In this example:The Derived class publicly inherits from the Base class, so the public and protected members of the Base class become public members in the Derived class.

The publicVar and publicMethod() members of the Base class are accessible through the Derived class.
The privateVar and privateMethod() members of the Base class are not accessible from outside the Base class itself.
The protectedVar and protectedMethod() members of the Base class are accessible within the Derived class (through inheritance) and can also be accessed by its methods.


The protected access modifier in C++ provides access to class members within the class itself and its derived classes. It allows derived classes to access the protected members of their base class, but restricts access to those members from outside the class hierarchy.

Here's a summary of the scope of the protected access modifier:

Within the Base Class: The protected members can be accessed by the methods and attributes of the base class itself.

Within Derived Classes: Protected members can be accessed by methods and attributes of derived classes that inherit from the base class.

Outside the Class Hierarchy: Protected members are not directly accessible from code outside the class hierarchy. This means that objects of unrelated classes or functions outside the class hierarchy cannot access the protected members.
*/