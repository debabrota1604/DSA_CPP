
#include<bits/stdc++.h>
using namespace std;
/*
We now have three distinct ways to coordinate between threads:
    mutex: mutual exclusion (lock), used to enforce critical sections and atomicity
    condition_variable: way for threads to coordinate and signal when a variable has changed (integrates a lock for the variable)
    semaphore: a generalization of a lock, where there can be n threads operating in parallel (a lock is a semaphore with n=1)

Mutual Exclusion (mutex):
A mutex is a simple lock that is shared between threads, used to protect critical regions of code or shared data structures.
        mutex m;
        mutex.lock()
        mutex.unlock()
A mutex is often called  a lock: the terms are mostly interchangeable
When a thread attempts to lock a mutex:
    Currently unlocked: the thread takes the lock, and continues executing
    Currently locked: the thread blocks until the lock is released by the current lock holder, at which point it attempts to take the lock again (and could compete with other waiting threads).
Only the current lock-holder is allowed to unlock a mutex
Deadlock can occur when threads form a circular wait on mutexes (e.g. dining philosophers)
Places we've seen an operating system use mutexes for us:
    All file system operation (what if two programs try to write at the same time? create the same file?)
    Process table (what if two programs call fork() at the same time?)


lock_guard<mutex>:
The lock_guard<mutex> is very simple: it obtains the lock in its constructor, and releases the lock in its destructor.
We use a lock_guard<mutex> so we don't have to worry about unlocking a mutex when we exit a block of code
*/

void function(mutex &m) {
    lock_guard<mutex> lg(m); // m is now locked
    while (true) {
        if (condition1) return; // lg automatically unlocked on return
        // ...
        if (condition2) break;
    }
    // mutex will be unlocked after this line when lg goes out of scope
}

/*
A lock guard is a good when you always want to release a lock on leaving a block.
    If you want to unlock it later or later, don't use it (or change block structure)
Using a lock guard is a good idea when control flow is complex (returns, breaks, multiple exit points), such that the lock would have to be unlocked in multiple places

conditional_variable:

The pattern of waiting on a condition variable within a while loop that checks the
condition is so common there's a variant of wait that supports it.
*/

template <Predicate pred>
void condition_variable_any::wait(mutex& m, Pred pred) {
 while (!pred()) wait(m);
}

/*
Pred is a function that returns true or false. You can use a lambda function for it:
*/

static void waitForPermission(size_t& permits, condition_variable_any& cv, mutex& m) {
 lock_guard<mutex> lg(m);
 cv.wait(m, [&permits] { return permits > 0; });
 permits--;
}

/*
Some times the operating system has used condition variables for us
    Reading from a pipe: caller waits until someone writing to the pipe wakes it up
    Writing to a pipe: caller waits until there's space in the pipe
    Waiting until a child has exited

semaphore:

The semaphore class is not built in to C++, but it is a basic synchronization primitive
You declare a semaphore with a maximum value (e.g., permits in last lecture)
*/

semaphore permits(5); // this will allow five permits

/*
A thread uses a semaphore by decrementing it with a call to wait; if the semaphore value is 0, the thread blocks.
A thread releasing a semaphore calls signal, this increments the value and triggers waiting threads to resume (and try to decrement).
*/

permits.wait(); // if five other threads currently hold permits, this will block
// only five threads can be here at once
permits.signal(); // if other threads are waiting, a permit will be available

/*
A mutex is a special case of a semaphore with a value of 1. If you need a lock, use a mutex. Unlike semaphores, one error checking benefit of a mutex is that it can only be released by the lock-holder. But in cases when you need to allow a group of threads to be in a section of code (e.g., want to limit parallelism 2 <= n  <= k), use a semaphore.
*/