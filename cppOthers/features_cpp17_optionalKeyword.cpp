#include <iostream>
#include <optional>

int main() {
    // Creating and checking for value presence
    std::optional<int> maybeValue;  // Empty
    std::optional<double> pi = 3.14159;

    if (!maybeValue.has_value()) {
        std::cout << "maybeValue is empty." << std::endl;
    }

    if (pi) {
        std::cout << "pi contains a value: " << pi.value() << std::endl;
    }

    // Accessing values and providing defaults
    maybeValue = 42; // Assigning a value
    if (maybeValue.has_value()) {
        int value = maybeValue.value();
        std::cout << "maybeValue contains a value: " << value << std::endl;
    }

    double defaultValue = 2.0;
    double piValue = pi.value_or(defaultValue);
    std::cout << "piValue (with default): " << piValue << std::endl;

    // Resetting and clearing optional
    maybeValue.reset();
    if (!maybeValue.has_value()) {
        std::cout << "maybeValue is empty after reset." << std::endl;
    }

    // Using std::optional in a function
    std::optional<int> result = divide(10, 2);
    if (result.has_value()) {
        std::cout << "Result of division: " << result.value() << std::endl;
    } else {
        std::cout << "Division by zero or invalid input." << std::endl;
    }

    // Comparison
    std::optional<int> a = 42;
    std::optional<int> b = 42;
    
    if (a == b) {
        std::cout << "a and b are equal." << std::endl;
    }

    return 0;
}

std::optional<int> divide(int dividend, int divisor) {
    if (divisor == 0) {
        return std::nullopt; // No value to optional
    }
    return dividend / divisor;
}
