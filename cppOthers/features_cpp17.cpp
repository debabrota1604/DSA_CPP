#include <iostream>
#include <vector>
#include <optional>
#include <variant>
#include <any>
#include <string_view>

// C++17 Structured Bindings: the lvalue can be broken into multiple small parameters
void structuredBindingsExample() {
    std::pair<int, double> values = {42, 3.14};
    auto [x, y] = values;

    std::cout << "x: " << x << ", y: " << y << std::endl;
}

// C++17 std::optional
void optionalExample() {
    std::optional<int> maybeValue;
    std::optional<int> definitelyValue = 42;

    if (maybeValue.has_value()) {
        std::cout << "maybeValue: " << maybeValue.value() << std::endl;
    }
    else {
        std::cout << "maybeValue is empty." << std::endl;
    }

    if (definitelyValue.has_value()) {
        std::cout << "definitelyValue: " << definitelyValue.value() << std::endl;
    }
}

// C++17 std::variant
void variantExample() {
    std::variant<int, double, std::string> data = 42;
    
    if (std::holds_alternative<int>(data)) {
        int value = std::get<int>(data);
        std::cout << "Variant value: " << value << std::endl;
    }
}

// C++17 std::any
void anyExample() {
    std::any data = 3.14;
    
    if (data.type() == typeid(double)) {
        double value = std::any_cast<double>(data);
        std::cout << "Any value: " << value << std::endl;
    }
}

// C++17 std::string_view
void stringViewExample() {
    std::string text = "Hello, C++17!";
    std::string_view view(text);

    std::cout << "Length: " << view.length() << std::endl;
    std::cout << "First 5 characters: " << view.substr(0, 5) << std::endl;
}

int main() {
    structuredBindingsExample();
    optionalExample();
    variantExample();
    anyExample();
    stringViewExample();
    
    return 0;
}
