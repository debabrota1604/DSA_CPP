#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <ranges>
#include <compare>
#include<coroutine>

// Concept for checking if a type is iterable
template <typename T>
concept Iterable = requires(T t) {
    begin(t);
    end(t);
};

// Function using concepts, which provide a way to specify and check requirements for template arguments. Concepts allow you to express constraints on template parameters.
template <Iterable Container>
void printContainer(const Container& container) {
    for (const auto& item : container) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

struct Generator {
    struct promise_type {
        int current_value;

        auto get_return_object() {
            return Generator{std::coroutine_handle<promise_type>::from_promise(*this)};
        }

        auto initial_suspend() {
            return std::suspend_never{};
        }

        auto final_suspend() {
            return std::suspend_never{};
        }

        void return_void() {}

        auto yield_value(int value) {
            current_value = value;
            return std::suspend_always{};
        }

        void unhandled_exception() {
            std::terminate();
        }
    };

    std::coroutine_handle<promise_type> coro;

    bool move_next() {
        coro.resume();
        return !coro.done();
    }

    int current_value() {
        return coro.promise().current_value;
    }

    ~Generator() {
        if (coro) {
            coro.destroy();
        }
    }
};

Generator range(int from, int to) {
    for (int i = from; i < to; ++i) {
        co_yield i;
    }
}

// Feature constexpr (Improved)
constexpr auto square = [](int x) {
    if (x < 0) return -x;
    return x;
};

int main() {
    // Concepts example
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    printContainer(numbers);

    // Ranges example: the Ranges library, providing a set of new algorithms and range adaptors for working with sequences. This simplifies and enhances the manipulation of ranges and containers.
    auto evenNumbers = numbers | std::views::filter([](int x) { return x % 2 == 0; });
    printContainer(evenNumbers);

    // coroutines example: allow you to write asynchronous and cooperative multitasking code more easily. Coroutines provide a way to pause and resume the execution of functions.
    auto seq = range(1, 6);
    while (seq.move_next()) {
        std::cout << seq.current_value() << " ";
    }

    // Three-way comparison example: the "spaceship" operator (<=>) for three-way comparisons, allowing you to simplify comparisons and ordering of objects.
    struct MyClass {
        int value;
        auto operator<=>(const MyClass& other) const { //overloadable operator
            return value <=> other.value;
        }
    };

    MyClass a = {10};
    MyClass b = {20};

    auto result = a <=> b; //Result can be -ve, 0 or +ve.

    if (result < 0) {
        std::cout << "a is less than b." << std::endl;
    } else if (result == 0) {
        std::cout << "a is equal to b." << std::endl;
    } else {
        std::cout << "a is greater than b." << std::endl;
    }

    // Improvement on constExpr: including support for lambda expressions, if statements, and more, enabling more powerful compile-time computations.
    constexpr int result = square(5);

    return 0;
}
/*
C++20 Features:
1. Modules: offer a new way to organize and manage code. Modules help eliminate header files and improve compilation times by allowing you to encapsulate and control the visibility of code.

// File: math.cppm
export module math;

export int add(int a, int b) {
    return a + b;
}
// File: main.cpp
import math;

int main() {
    int result = add(3, 4);
    return 0;
}


2. Concepts: provide a way to specify and check requirements for template arguments
3. Coroutines: write asynchronous and cooperative multitasking code more easily.
4. Ranges: New set of algorithms and range adaptors to work better with sequences.
5. Three-way comparisons: single parameter that checks equal, less than and greater than
6. Const-expr improvements: Extra support for 'if' statements in lambda expressions.
*/ 
