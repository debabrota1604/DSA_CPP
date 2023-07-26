#include <iostream>

/*
Run-Time Polymorphism (Virtual Functions): Run-time polymorphism is achieved through virtual functions and dynamic binding. It allows a derived class to provide its own implementation of a virtual function,  and the appropriate function is determined at run-time based on the actual object's type.
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

class Square : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a square." << std::endl;
    }
};

int main() {
    Shape* shape1 = new Circle();
    Shape* shape2 = new Square();

    shape1->draw(); // Calls the draw() function of Circle class
    shape2->draw(); // Calls the draw() function of Square class

    delete shape1;
    delete shape2;

    return 0;
}

/*
Run-time polymorphism is achieved through virtual functions, which allow derived classes  Circle and Square to provide their own implementations of the draw() function. 

The actual implementation of the function to call is determined at run time based on the object's type during the program's execution.
*/
