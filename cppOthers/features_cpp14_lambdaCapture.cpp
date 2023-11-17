#include <iostream>
#include <vector>

/*
In C++14, lambda captures allow you to capture variables from the surrounding scope into a lambda function. There are two ways to perform captures:

Value Capture ([=]): Capture variables by value. The lambda function creates copies of the captured variables. The variables from the surrounding scope are not modified.

Reference Capture ([&]): Capture variables by reference. The lambda function operates directly on the original variables from the surrounding scope, allowing modifications.

Here's a C++14 code example demonstrating lambda captures and their use cases:
*/

int main() {
    int x = 10;
    int y = 20;

    // Lambda with value capture (x is captured by value)
    auto valueCapture = [x](int a) {
        std::cout << "Value Capture: x = " << x << ", a = " << a << std::endl;
        // x++; // Error: Can't modify x, it's captured by value
    };

    // Lambda with reference capture (y is captured by reference)
    auto referenceCapture = [&y](int b) {
        std::cout << "Reference Capture: y = " << y << ", b = " << b << std::endl;
        y++; // Modifying y is allowed
    };

    x = 42;
    y = 84;

    valueCapture(100);      // x remains 42 inside the lambda
    referenceCapture(200);  // y is modified, becomes 85

    std::cout << "After Lambdas: x = " << x << ", y = " << y << std::endl;



    //Use of value capture by reference

    // Example 1: Accumulating Values
    int sum = 0;
    auto addToSum = [&sum](int value) {
        sum += value;
    };
    addToSum(5);
    addToSum(10);
    addToSum(20);
    std::cout << "Sum after lambda calls: " << sum << std::endl;

    // Example 2: Modifying Variables
    int i = 10;
    auto doubleValue = [&i]() {
        i *= 2;
    };
    std::cout << "Before lambda: i = " << i << std::endl;
    doubleValue();
    std::cout << "After lambda: i = " << i << std::endl;

    // Example 3: Implementing Custom Actions
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    auto squareValues = [&numbers]() {
        for (int& num : numbers) {
            num *= num;
        }
    };
    squareValues();
    std::cout << "Squared values: ";
    for (const int& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    /*
    Output:
    Value Capture: x = 10, a = 100
    Reference Capture: y = 84, b = 200
    After Lambdas: x = 42, y = 85
    Sum after lambda calls: 35
    Before lambda: i = 10
    After lambda: i = 20
    Squared values: 1 4 9 16 25 
    */


    return 0;
}

/*
In this code:

    We declare two lambdas, valueCapture and referenceCapture.

    valueCapture captures x by value, meaning it creates a copy of x inside the lambda. Any modification to x inside the lambda does not affect the original x outside the lambda.

    referenceCapture captures y by reference, allowing it to modify the original y directly.

    After defining the lambdas, we change the values of x and y.

    When we call valueCapture(100), it prints the value of the captured x (which is 42) and a (which is 100), but attempting to modify x inside the lambda would result in an error.

    When we call referenceCapture(200), it prints the value of the captured y (which is 84), and b (which is 200). It also modifies y, changing its value to 85.

    After the lambdas have executed, we print the final values of x and y, showing the effect of captures.

Lambda captures are useful when you want to create small, self-contained functions that operate on variables from their surrounding scope, either by value or by reference, without needing to pass those variables explicitly as function arguments. This makes lambda functions powerful and flexible for various use cases, including algorithms, parallelism, and callback functions.
*/