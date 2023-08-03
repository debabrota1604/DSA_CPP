#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

//For mutex Example
std::mutex mtx;

// For Semaphore Example
std::mutex sp;
std::condition_variable cv;
int resourceCounter = 2; // Semaphore with 2 resources available

/*
A mutex (short for mutual exclusion) is a locking mechanism used to protect shared resources from simultaneous access by multiple threads. 
A mutex allows only one thread to acquire the lock at a time. 
If a thread attempts to acquire the mutex while it's already locked by another thread, the thread will be blocked (put to sleep) until the mutex becomes available.
Example of Mutex:
*/
void sharedResourceAccess_mutex() {
    mtx.lock();
    // Critical section: Access the shared resource safely
    std::cout << "Thread " << std::this_thread::get_id() << " is accessing the shared resource." << std::endl;
    mtx.unlock();
}

/*
A semaphore is a synchronization mechanism that allows multiple threads to access shared resources while limiting the number of threads that can access the resource simultaneously. 
It maintains a counter that represents the number of available resources. 
Threads can request access to the semaphore, and if the counter is greater than zero, the thread can proceed to access the resource. 
When a thread is done using the resource, it releases the semaphore, incrementing the counter and allowing other waiting threads to acquire the resource.
Example of Semaphore:
*/
bool isResourceAvailable2() {
    return resourceCounter > 0;
}
void sharedResourceAccess_semaphore() {
    std::unique_lock<std::mutex> lock(sp);
    //cv.wait(lock, []() { return resourceCounter > 0; }); //Lambda Version
    cv.wait(lock, isResourceAvailable2);
    resourceCounter--; // Decrease the counter to reserve the resource
    lock.unlock();

    // Critical section: Access the shared resource safely
    std::cout << "Thread " << std::this_thread::get_id() << " is accessing the shared resource." << std::endl;

    // Release the resource when done
    lock.lock();
    resourceCounter++;
    lock.unlock();
    cv.notify_one(); // Notify other waiting threads that a resource is available
}

int main() {

    /* Mutex Example */
    std::thread t1(sharedResourceAccess_mutex);
    std::thread t2(sharedResourceAccess_mutex);

    t1.join();
    t2.join();
    // In this example, we use a std::mutex named mtx to protect the critical section where the shared resource is accessed. Only one thread will be allowed to enter the critical section at a time, ensuring safe access to the shared resource.

    /* Semaphore Example */
    std::thread t5(sharedResourceAccess_semaphore);
    std::thread t6(sharedResourceAccess_semaphore);
    std::thread t7(sharedResourceAccess_semaphore);

    t5.join();
    t6.join();
    t7.join();
    // In this example, we use a semaphore-like mechanism with resourceCounter to limit the number of threads accessing the shared resource to 2 at a time. The std::condition_variable (cv) and the lambda function in the cv.wait ensure that a thread waits until a resource becomes available before entering the critical section.
    
    return 0;
}

/*

Differences between Mutex and Semaphore:
    Mutex allows only one thread to access the shared resource at a time, while Semaphore can allow multiple threads to access the shared resource simultaneously (depending on the value of the semaphore counter).
    Mutex is typically used for mutual exclusion, protecting critical sections with exclusive access, while Semaphore is used to control access to a shared resource with a limited number of available instances.
    Mutex has binary behavior (locked or unlocked), whereas Semaphore has a count value that can represent the number of available resources.
    Mutex is usually simpler to use when you only need to protect critical sections, while Semaphore provides more control when multiple resources are available, and you want to limit concurrent access.

The choice between using a Mutex or a Semaphore depends on the specific requirements of your concurrent application and the level of control you need over resource access.

*/