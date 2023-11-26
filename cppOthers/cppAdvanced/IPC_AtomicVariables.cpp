/*
In C++, an atomic variable is a special type of variable that allows for atomic operations on shared data in a multithreaded environment. Atomic variables ensure that operations on the shared data are performed atomically, meaning they are indivisible and cannot be interrupted or interleaved by other threads. This prevents data races and ensures consistent behavior in concurrent programs.

The C++ Standard Library provides the <atomic> header, which defines the std::atomic template class to work with atomic variables. This template allows you to create atomic variables of various types, such as std::atomic<int>, std::atomic<double>, and std::atomic<bool>, among others.

Here are some key features and characteristics of atomic variables in C++:

1. Atomic Operations: Atomic variables support atomic operations like load(), store(), and various atomic arithmetic operations like fetch_add(), fetch_sub(), fetch_and(), fetch_or(), and so on. These operations ensure that the read-modify-write operations on the shared data are performed atomically without any interference from other threads.

2. Memory Ordering: Atomic operations can have different memory ordering constraints specified using memory order parameters. The memory order parameters (std::memory_order) define how atomic operations are ordered with respect to other memory accesses in the program. They provide flexibility to balance performance and synchronization requirements.

3. Lock-Free and Wait-Free: Some atomic operations on certain platforms are lock-free or wait-free, which means they don't require explicit locking or waiting and are guaranteed to complete in a finite number of steps, regardless of contention from other threads.

4. Compiler and Hardware Support: Atomic operations are typically implemented using specialized CPU instructions or compiler intrinsics, making them efficient and well-optimized for the underlying hardware architecture.

5. Thread Safety: Atomic variables provide a level of thread safety, ensuring that operations on them can be safely performed in a multithreaded environment without data races or undefined behavior.

6. Data Race Avoidance: By using atomic variables, you can avoid data races in concurrent programs, as the atomic operations ensure that shared data is accessed in a thread-safe manner.

Here's a simple example of using atomic variables in C++:
*/

#include <iostream>
#include <atomic>
#include <thread>

std::atomic<int> sharedCounter(0);

void incrementCounter() {
    for (int i = 0; i < 10000; ++i) {
        sharedCounter.fetch_add(1, std::memory_order_relaxed);
    }
}

int main() {
    std::thread t1(incrementCounter);
    std::thread t2(incrementCounter);

    t1.join();
    t2.join();

    std::cout << "Final counter value: " << sharedCounter << std::endl;
    return 0;
}


/*
In this example, the sharedCounter is an atomic variable, and two threads increment its value concurrently using the fetch_add operation. The use of std::memory_order_relaxed specifies the memory ordering, indicating that the operation does not impose any additional synchronization constraints.

Atomic variables are powerful tools for writing concurrent and thread-safe code in C++, but it's essential to understand their appropriate use, memory ordering semantics, and when additional synchronization mechanisms like mutexes or condition variables might be necessary for more complex operations or data dependencies.
*/

//why should we use atomic over other thread safe mechanisms?

/*
Using atomic variables over other thread-safe mechanisms like mutexes or semaphores has several advantages, and the choice depends on the specific requirements and nature of the data and operations in the multithreaded environment. Here are some reasons why you might prefer using atomic variables:
    1. Performance: Atomic operations are typically faster than using traditional synchronization mechanisms like mutexes. Atomic variables often utilize specialized hardware instructions or compiler optimizations for efficient and lock-free execution. As a result, they can be more suitable for scenarios where performance is critical, and frequent access to shared data is required.
    2. Simplicity and Ease of Use: Atomic variables are straightforward to use compared to mutexes and other synchronization primitives. They reduce the complexity of code by avoiding the need to lock and unlock mutexes explicitly. As atomic variables ensure thread safety without the need for external locking mechanisms, code maintenance becomes more manageable.
    3. Avoiding Deadlocks: Deadlocks can occur in multithreaded programs when multiple threads compete for shared resources, leading to circular waiting. Atomic variables inherently avoid deadlocks because they do not involve explicit locking and unlocking. Therefore, atomic operations cannot block other threads and prevent circular waiting situations.
    4. Lower Overhead: Atomic variables have lower overhead than traditional synchronization mechanisms because they don't involve context switching or thread blocking. The lack of thread contention makes atomic operations more scalable in scenarios with a large number of threads.
    5. Synchronization Granularity: Atomic operations can be performed on individual data elements (e.g., individual integers or bools) instead of entire data structures. This allows fine-grained synchronization and can reduce contention among threads when they access different parts of the shared data.

However, it's essential to consider some limitations and caveats when using atomic variables:
    1. Limited Operations: Atomic variables support basic atomic operations like load, store, and simple arithmetic operations (e.g., increment, decrement). More complex operations may still require traditional synchronization mechanisms like mutexes or condition variables.
    2. Memory Ordering: Correct use of atomic variables requires understanding and setting appropriate memory ordering constraints. Choosing the right memory order is crucial to ensure the correct behavior of multithreaded operations and avoid subtle bugs.
    3. Data Dependencies: Atomic variables are best suited for scenarios with minimal data dependencies between threads. When complex interactions or data dependencies exist, traditional synchronization mechanisms may be necessary for correct and predictable behavior.

In summary, atomic variables offer a performance advantage, simpler code structure, and avoidance of deadlocks compared to traditional synchronization mechanisms. However, they are most effective for simple, fine-grained operations with minimal data dependencies among threads. For more complex interactions and data sharing, traditional synchronization mechanisms like mutexes and semaphores might be more appropriate.
*/


/*
Limitations of std::atomic:
    1. Limited Operations: std::atomic supports a limited set of atomic operations. Not all operations that might be considered atomic are provided. For example, complex operations involving multiple variables may require the use of locks.
    2. Performance Implications: Depending on the specific implementation and hardware architecture, using atomic operations might have performance implications. Atomic operations may involve memory barriers or other low-level mechanisms that can impact performance, especially in heavily contended scenarios.
    3. Memory Usage: Atomic operations may use additional memory or padding to ensure proper alignment and atomicity. This additional memory usage might be a concern in situations where memory usage needs to be minimized.
    4. Platform Dependence: The behavior of atomic operations can be platform-dependent. Different architectures may have different characteristics regarding atomic operations and memory consistency.
    5. Complexity: Working with atomic operations requires careful consideration of correctness and synchronization. Incorrect usage can lead to subtle and hard-to-debug issues such as data races or unexpected behavior.
    6. Limited Support for Non-Trivial Types: std::atomic is primarily designed for fundamental types. Using it with non-trivially copyable types or types with complex constructors/destructors may lead to unexpected behavior.
    7. No Support for User-Defined Atomic Types (Pre-C++20): Prior to C++20, std::atomic only supported a limited set of fundamental types. C++20 introduced the concept of atomic smart pointers, but more complex user-defined atomic types might still require additional synchronization mechanisms.
*/