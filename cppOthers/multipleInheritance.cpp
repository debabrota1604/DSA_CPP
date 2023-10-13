/*

In C++, multiple inheritance allows a class to inherit from more than one base class. 
This means that a derived class can have characteristics and functionalities from 
multiple parent classes. Let's look at a simple example of multiple inheritance:

*/

#include <iostream>

// Base class 1
class Shape {
public:
    virtual void draw() const {
        std::cout << "Drawing a shape." << std::endl;
    }
    virtual void diamondProblem(){
        std::cout<< "diamondProblem: In Shape class" << std::endl;
    }
};

// Base class 2
class Color {
public:
    virtual void fill() const {
        std::cout << "Filling with color." << std::endl;
    }
};

// Test which verison will be executed.
class ShapeCopy{
    public:
    virtual void diamondProblem(){
        std::cout << "diamondProblem: In ShapeCopy" << std::endl;
    }
};

// Derived class with multiple inheritance
class ColoredShape : public Shape, public Color, public ShapeCopy {
public:
    void draw() const override {
        std::cout << "Drawing a colored shape." << std::endl;
    }
};

int main() {
    ColoredShape coloredShape;

    coloredShape.draw(); // Calls the overridden draw() function in ColoredShape
    coloredShape.fill(); // Calls the fill() function from the Color base class
    //coloredShape.diamondProblem(); // Throws compilation error

    return 0;
}


/*
In this example, we have two base classes Shape and Color, and a derived class ColoredShape 
that inherits from both Shape and Color. The ColoredShape class can access and use the functionalities of both base classes.

The ColoredShape class overrides the draw() function from the Shape class, which is marked as virtual, 
allowing for polymorphic behavior. It also uses the fill() function from the Color class without any modifications.

Keep in mind that multiple inheritance should be used judiciously, as it can lead to complexities in code 
and potential ambiguity if multiple base classes have functions with the same name. In such cases, you can 
use scope resolution (::) to specify which base class's function you want to call.
*/