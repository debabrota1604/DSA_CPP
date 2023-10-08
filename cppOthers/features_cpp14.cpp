#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

// Feature 1: Generic Lambdas
auto add = [](auto a, auto b) { return a + b; };

// Feature 2: Return Type Deduction for Functions
auto multiply(int a, int b) { return a * b; }

// Feature 3: Relaxed constexpr
constexpr int factorial(int n) {
    return n <= 1 ? 1 : n * factorial(n - 1);
}

// Feature 4: Binary Literals and Digit Separators
int binaryValue = 0b101010;
int bigNumber = 1'000'000;

int main() {
    // Feature 1: Generic Lambdas
    std::cout << "Generic Lambda: add(5, 7) = " << add(5, 7) << std::endl;
    std::cout << "Generic Lambda: add(3.14, 2.71) = " << add(3.14, 2.71) << std::endl;

    // Feature 2: Return Type Deduction for Functions
    std::cout << "Return Type Deduction: multiply(3, 4) = " << multiply(3, 4) << std::endl;
    std::cout << "Return Type Deduction: multiply(3.14, 2.71) = " << multiply(3.14, 2.71) << std::endl;

    // Feature 3: Relaxed constexpr
    std::cout << "Factorial (constexpr): factorial(5) = " << factorial(5) << std::endl;

    // Feature 4: Binary Literals and Digit Separators
    std::cout << "Binary Literal: binaryValue = " << binaryValue << std::endl;
    std::cout << "Digit Separator: bigNumber = " << bigNumber << std::endl;

    // Feature 5: Initialization of Variables in if Statements
    if (auto result = add(2, 3); result > 0) {
        std::cout << "Result is positive: " << result << std::endl;
    } else {
        std::cout << "Result is non-positive." << std::endl;
    }

    // Feature 6: Structured Bindings
    std::tuple<int, std::string, double> person = {42, "John Doe", 3.14};
    auto [age, name, pi] = person;
    std::cout << "Structured Binding - Age: " << age << ", Name: " << name << ", PI: " << pi << std::endl;

    // Feature 7: Lambda Captures with Initializers
    int x = 10;
    auto lambda = [y = x + 5]() { return y; };
    std::cout << "Lambda Capture with Initializer: lambda() = " << lambda() << std::endl;

    // Feature 8: Delegating Constructors
    class Example {
    public:
        Example() : Example(42) {} // Delegating constructor
        Example(int value) : value_(value) {}
        int getValue() const { return value_; }
    private:
        int value_;
    };
    Example example;
    std::cout << "Delegating Constructors: example.getValue() = " << example.getValue() << std::endl;

    return 0;
}
