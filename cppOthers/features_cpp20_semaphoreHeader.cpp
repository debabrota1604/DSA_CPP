/*
Here's an example of using semaphores in C++ with the help of the <semaphore> header introduced in C++20:
*/


#include <iostream>
#include <thread>
#include <semaphore>

int sharedResource = 0;
std::binary_semaphore sem(1);

void increment() {
    for (int i = 0; i < 100000; ++i) {
        sem.acquire();  // Acquire the semaphore
        sharedResource++;
        std::cout << sharedResource << std::endl;
        sem.release();  // Release the semaphore
    }
}

int main() {
    std::thread thread1(increment);
    std::thread thread2(increment);

    thread1.join();
    thread2.join();

    std::cout << "Shared resource value: " << sharedResource << std::endl;
    return 0;
}


/*
In this example, we have a shared resource (sharedResource) that is accessed by two threads concurrently. We use a binary semaphore (std::binary_semaphore) to protect access to the shared resource. The acquire method is called to acquire the semaphore before accessing the shared resource, and the release method is called to release the semaphore once the operation is complete.

By using semaphores, we ensure that only one thread can access the shared resource at a time, preventing race conditions and ensuring safe concurrent access.

Please note that the <semaphore> header and C++20 or later standards are required to use the standard C++ semaphore library. If you're working with an older C++ standard, you might need to use platform-specific or third-party libraries for semaphore support.
*/


/*
The same solution can be solved using mutex:

#include <iostream>
#include <thread>
#include <mutex>

int sharedResource = 0;
std::mutex mtx;

void increment() {
    for (int i = 0; i < 100000; ++i) {
        std::lock_guard<std::mutex> lock(mtx); // Lock the mutex
        sharedResource++;
    }
}

int main() {
    std::thread thread1(increment);
    std::thread thread2(increment);

    thread1.join();
    thread2.join();

    std::cout << "Shared resource value: " << sharedResource << std::endl;
    return 0;
}


In this modified example, we use a std::mutex (specifically, a std::lock_guard for convenient locking) to protect access to the shared resource. The lock operation locks the mutex when a thread enters the critical section and unlocks it when the thread exits, ensuring that only one thread can access the shared resource at a time.

Using mutexes is another way to synchronize access to shared resources and avoid race conditions in multithreaded programs. Both mutexes and semaphores can be used depending on the specific requirements of your application.
*/