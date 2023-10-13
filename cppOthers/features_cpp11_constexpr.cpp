#include <iostream>
#include <array>
#include <type_traits>

// Example of a constexpr variable (C++11)
constexpr int x = 42;
constexpr double pi = 3.14159;
constexpr char greeting[] = "Hello";

// Example of a constexpr function (C++11)
constexpr int square(int x) {
    return x * x;
}

// Example of a constexpr if (C++17)
template <typename T>
constexpr auto add_one(T x) {
    if constexpr (std::is_integral<T>::value) {
        return x + 1;
    } else {
        return x;
    }
}

// Example of a constexpr class (C++11)
struct Point {
    int x, y;
    constexpr Point(int a, int b) : x(a), y(b) {}
};

// Example of constexpr std::array initialization (C++11)
constexpr std::array<int, 3> arr = {1, 2, 3};

int main() {
    // Using constexpr variables and functions
    std::cout << "x = " << x << std::endl;
    std::cout << "pi = " << pi << std::endl;
    std::cout << "greeting = " << greeting << std::endl;
    std::cout << "square(5) = " << square(5) << std::endl;
    std::cout << "add_one(5) = " << add_one(5) << std::endl;
    
    // Using a constexpr class
    constexpr Point p(10, 20);
    std::cout << "Point p: x = " << p.x << ", y = " << p.y << std::endl;
    
    // Using constexpr std::array
    for (int value : arr) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}
