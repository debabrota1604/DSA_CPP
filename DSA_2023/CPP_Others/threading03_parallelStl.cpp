#include <iostream>
#include <algorithm>
#include <vector>

/*
C++17 introduced parallel algorithms to the STL, allowing you to perform some standard algorithms in parallel using multiple threads. You can use std::execution::par as the execution policy for parallel execution.

*/

int main() {
    std::vector<int> data = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};

    std::for_each(std::execution::par, data.begin(), data.end(), [](int val) {
        std::cout << val << " ";
    });

    return 0;
}
