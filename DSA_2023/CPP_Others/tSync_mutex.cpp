#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx; // Declare a mutex

void printNumber(int num) {
    mtx.lock(); // Acquire the lock before accessing the shared resource
    std::cout << "Thread ID: " << std::this_thread::get_id() << " - Number: " << num << std::endl;
    mtx.unlock(); // Release the lock after accessing the shared resource
}

int main() {
    const int numThreads = 5;
    std::thread threads[numThreads];

    // Launch threads
    for (int i = 0; i < numThreads; ++i) {
        threads[i] = std::thread(printNumber, i + 1);
    }

    // Wait for threads to finish
    for (int i = 0; i < numThreads; ++i) {
        threads[i].join();
    }

    return 0;
}


/*
In this example, we have a shared function printNumber() that accesses a shared resource (in this case, std::cout). 
We use a std::mutex named mtx to synchronize access to the shared resource. Before accessing the shared resource, 
each thread acquires the lock using mtx.lock(), and after finishing the operation, it releases the lock using mtx.unlock().

The output may not be sequential because threads are running concurrently. However, the use of the mutex ensures 
that the shared resource (the console output in this case) is accessed safely and prevents potential data races 
and unexpected behavior that could occur without synchronization.

Remember to use mutexes judiciously to protect shared resources and to acquire and release the locks in the 
appropriate places to avoid deadlocks and maximize concurrency.
*/