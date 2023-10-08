/*
Learning about lambda functions in C++ is a great step towards understanding modern C++ programming. Lambda functions provide a concise way to create small, anonymous functions, and they are a powerful feature in C++. To get started with learning about lambda functions, you can follow these steps:

Understand Function Objects (Functors):
    Before diving into lambda functions, it's helpful to understand function objects or functors. Function objects are objects that can be called like functions. Understanding these will provide context for lambda functions.

Learn the Syntax:
    Lambda functions have a specific syntax:

        [capture clause](parameters) -> return_type { function_body }

    The capture clause allows you to capture variables from the surrounding scope.
    Parameters are the input arguments to the lambda.
    The return_type is optional and can be deduced by the compiler.
    The function_body contains the code to be executed.

Study Captures:
    Understand the different ways to capture variables:

        [=] captures all variables by value.
        [&] captures all variables by reference.
        [x] captures a specific variable x by value.
        [&y] captures a specific variable y by reference.


Understand Use Cases:
    Learn when and why you would use lambda functions. They are commonly used in:

        Algorithms like std::for_each, std::transform, etc.
        Callback functions.
        Short, throwaway functions for local tasks.
        Custom sort functions.


Advanced Topics:
As you become more comfortable with lambda functions, you can explore more advanced topics like capturing with move semantics, lambda expressions in generic code, and using lambda functions in multithreaded applications.

Remember that lambda functions are a feature introduced in C++11 and improved in subsequent C++ standards (C++14, C++17, etc.). Make sure you're using a compiler that supports at least C++11 for lambda functions.

Start with small, manageable examples, and gradually increase the complexity of your lambda functions as you become more familiar with the syntax and capabilities. Practice is the key to mastering this feature and using it effectively in your C++ programs.
*/

#include <iostream>

int main() {
    // Example 1: Simple Lambda Expression
    auto greeting = []() {
        std::cout << "Hello, Lambda!" << std::endl;
    };
    greeting();  // Call the lambda function

    // Example 2: Lambda with Parameters
    auto add_ = [](int a, int b) {
        return a + b;
    };
    int result = add_(3, 4);
    std::cout << "Result of add(3, 4): " << result << std::endl;

    // Example 3: Lambda with Capture Clause
    int x = 10;
    auto square = [x](int num) {
        return x * x * num;
    };
    result = square(3);
    std::cout << "Result of square(3): " << result << std::endl;

    // Example 4: Lambda with Reference Capture
    int y = 20;
    auto increment = [&y]() {
        y++;
    };
    increment();
    std::cout << "After increment: y = " << y << std::endl;


    //Version wise lambda function improvements

    // C++14 Lambda Features
    // Feature 1: Generic Lambdas (C++14)
    auto add = [](auto a, auto b) {
        return a + b;
    };
    std::cout << "Generic Lambda (C++14): " << add(5, 7) << std::endl;
    std::cout << "Generic Lambda (C++14): " << add(3.14, 2.71) << std::endl;

    // Feature 2: Return Type Deduction for Functions (C++14)
    auto multiply = [](int a, int b) {
        return a * b;
    };
    std::cout << "Return Type Deduction (C++14): " << multiply(3, 4) << std::endl;
    std::cout << "Return Type Deduction (C++14): " << multiply(3.14, 2.71) << std::endl;

    // C++17 Lambda Features
    // Feature 3: Structured Bindings in Lambda Return (C++17)
    auto getPair = []() {
        return std::make_pair(42, "Hello");
    };
    auto [number, text] = getPair();
    std::cout << "Structured Bindings in Lambda Return (C++17): " << number << ", " << text << std::endl;

    // Feature 4: if with Initialization (C++17)
    int value = 42;
    auto printValue = [v = value]() {
        std::cout << "if with Initialization (C++17): " << v << std::endl;
    };
    printValue();

    // C++20 Lambda Features
    // Feature 5: Lambda with Init-Capture (C++20)
    int counter = 0;
    auto incrementCounter = [count = 0]() mutable {
        count++;
        return count;
    };
    std::cout << "Lambda with Init-Capture (C++20): " << incrementCounter() << std::endl;

    // Feature 6: Lambda as std::function (C++20)
    // std::function<int(int, int)> lambdaAsFunction = [](int a, int b) {
    //     return a * b;
    // };
    // std::cout << "Lambda as std::function (C++20): " << lambdaAsFunction(3, 4) << std::endl;

    // C++23 Lambda Features (Based on C++23 Draft)
    // Feature 7: Lambda with Range-Based for Loop (C++23)
    // std::vector<int> numbers = {1, 2, 3, 4, 5};
    // auto lambdaForRange = [&sum = numbers[0]]() mutable {
    //     for (int num : numbers) {
    //         sum += num;
    //     }
    // };
    // lambdaForRange();
    // std::cout << "Lambda with Range-Based for Loop (C++23): Sum = " << numbers[0] << std::endl;


    return 0;
}
