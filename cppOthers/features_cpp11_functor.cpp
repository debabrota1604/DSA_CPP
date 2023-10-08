/*
In C++, a functor, often referred to as a "function object," is an object that acts like a function or behaves as if it were a function. Functors are a powerful and flexible concept in C++ and can be used in various situations where you need to encapsulate behavior and treat it as an object.

Here are some key aspects and uses of functors in C++:

Callable Objects: Functors are callable objects, meaning they can be invoked like functions. You can use them in the same way you use regular functions or function pointers.

Custom Behavior: Functors allow you to define custom behavior that can be used in algorithms, containers, and other contexts. This is particularly useful when you need to apply specific logic to data elements.

Stateful Behavior: Functors can maintain state, which is often not possible with regular functions. This enables functors to remember information between calls, making them suitable for tasks that require context or memory.

Operator Overloading: Functors often make use of operator overloading. You can define your own operator overloads (e.g., operator()), allowing you to create objects that behave like functions of various arities.

Flexibility: Functors can be used in standard library algorithms such as std::for_each, std::transform, and std::sort. They can also be used in custom data structures and libraries to encapsulate specific behavior.
*/
#include <iostream>
#include <vector>
#include <algorithm>

// Define a functor for custom sorting
class CustomComparator {
public:
    bool operator()(int a, int b) const {
        // Sort in descending order
        return a > b;
    }
};

// Define a functor for squaring elements
class SquareFunctor {
public:
    int operator()(int x) const {
        return x * x;
    }
};

// Define a functor for filtering even numbers
class IsEvenFunctor {
public:
    bool operator()(int x) const {
        return x % 2 == 0;
    }
};

int main() {
    // Example 1: Sorting with Custom Comparator
    std::vector<int> numbers1 = {5, 2, 9, 1, 5, 6};
    CustomComparator comparator;
    std::sort(numbers1.begin(), numbers1.end(), comparator);
    std::cout << "Sorted in descending order: ";
    for (int num : numbers1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Example 2: Transforming Elements
    std::vector<int> numbers2 = {1, 2, 3, 4, 5};
    SquareFunctor square;
    std::transform(numbers2.begin(), numbers2.end(), numbers2.begin(), square);
    std::cout << "Squared values: ";
    for (int num : numbers2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Example 3: Filtering Elements
    std::vector<int> numbers3 = {1, 2, 3, 4, 5, 6};
    IsEvenFunctor isEven;
    auto it = std::remove_if(numbers3.begin(), numbers3.end(), isEven);
    numbers3.erase(it, numbers3.end());
    std::cout << "Even numbers: ";
    for (int num : numbers3) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
