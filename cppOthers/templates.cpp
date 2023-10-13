/*
Templating in C++ allows you to write generic code that can work with multiple data types without having to rewrite the same logic for each data type. Templates enable you to define functions, classes, and  even variables that can accept data types as parameters. This feature is known as "generic programming"  and is one of the powerful aspects of C++. There are two main types of templates in C++:

1. Function Templates:
Function templates allow you to define functions that can work with different data types. The syntax for  function templates uses the template keyword followed by the template parameter(s) enclosed in angle brackets (<>).  The template parameter(s) represent the generic data type(s) that the function can work with.
*/

#include <iostream>

// Function template to find the maximum of two values
template<typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    int result1 = max(5, 10); // Calls max<int>(5, 10)
    double result2 = max(3.14, 2.71); // Calls max<double>(3.14, 2.71)

    std::cout << "Max of 5 and 10 is: " << result1 << std::endl;
    std::cout << "Max of 3.14 and 2.71 is: " << result2 << std::endl;

    return 0;
}


/*
Class Templates:
Class templates allow you to define classes that can work with different data types. 
The syntax for class templates is similar to function templates, but the template parameter(s) apply to the entire class definition.
*/


// Class template for a generic pair
template<typename T1, typename T2>
class Pair {
public:
    Pair(T1 first, T2 second) : first_(first), second_(second) {}

    void display() {
        std::cout << "First: " << first_ << ", Second: " << second_ << std::endl;
    }

private:
    T1 first_;
    T2 second_;
};

int main() {
    Pair<int, double> myPair(42, 3.14);
    myPair.display(); // Displays "First: 42, Second: 3.14"

    Pair<std::string, bool> anotherPair("Hello", true);
    anotherPair.display(); // Displays "First: Hello, Second: 1"

    return 0;
}

/*
Templates provide a way to write more generic and reusable code in C++. 
They are widely used in standard C++ library containers, algorithms, and other utilities to support generic programming paradigms. 
Templates allow you to write code that adapts to different data types at compile time, making C++ a highly flexible and powerful programming language.
*/