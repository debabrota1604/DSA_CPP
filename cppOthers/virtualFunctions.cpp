#include<bits/stdc++.h>
using namespace std;

/*
In C++, both virtual functions and pure virtual functions are used to achieve polymorphism, allowing a derived class to provide its own implementation of a function defined in a base class. However, there are key differences between them:

*/

/*
Virtual Functions:
    A virtual function is a function declared in the base class with the virtual keyword. It allows a derived class to override the base class's implementation of the function. The base class provides a default implementation of the virtual function, which can be overridden in the derived class using the same function signature. A virtual function in the base class can have an implementation, but it is not required to have one.

*/

class Shape {
public:
    virtual void draw() {
        std::cout << "Drawing a shape." << std::endl;
    }
};

class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a circle." << std::endl;
    }
};


/*
Pure Virtual Functions:
    A pure virtual function is a virtual function that is declared in the base class with the virtual keyword and assigned the value 0 (pure specifier) as its implementation. It serves as a placeholder for a function that must be implemented in the derived class. A class containing at least one pure virtual function becomes an abstract class, and objects of the abstract class cannot be created. Derived classes must override all pure virtual functions to be considered concrete classes and allow object instantiation.
*/

class Shape2 {
public:
    virtual void draw() = 0; // Pure virtual function
};

class Circle : public Shape2 {
public:
    void draw() override {
        std::cout << "Drawing a circle." << std::endl;
    }
};


/*
In this example, Shape is an abstract class because it contains a pure virtual function draw(). You cannot create objects of the Shape class, but you can create objects of its derived classes, such as Circle, which must override the draw() function to be a concrete class.

Pure virtual functions provide a way to define an interface in the base class that must be implemented by the derived classes. They play a significant role in achieving polymorphism and creating class hierarchies in C++.
*/