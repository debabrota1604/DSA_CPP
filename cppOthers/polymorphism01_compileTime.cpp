#include <iostream>

/*
Compile-Time Polymorphism (Function Overloading): Function overloading is a form of compile-time polymorphism where multiple functions with the same name but different parameter lists can be defined in the same scope. The appropriate function is called based on the number or type of arguments passed during compilation.
*/

class MathOperations {
public:
    int add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }
};

int main() {
    MathOperations math;
    std::cout << math.add(5, 10) << std::endl;        // Calls the int add(int a, int b) function
    std::cout << math.add(3.14, 2.71) << std::endl;  // Calls the double add(double a, double b) function

    return 0;
}

/*
In this example, we have two types of polymorphism. Function overloading allows the MathOperations class to have two add() functions with different parameter types, and the appropriate function is chosen at compile time based on the arguments passed.
*/
