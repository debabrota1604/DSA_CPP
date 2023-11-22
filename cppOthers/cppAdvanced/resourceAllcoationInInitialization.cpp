// This note is taken from https://en.cppreference.com/w/cpp/language/raii

/*
Resource Acquisition Is Initialization or RAII, is a C++ programming technique[1][2] which binds the life cycle of a resource that must be acquired before use (allocated heap memory, thread of execution, open socket, open file, locked mutex, disk space, database connection—anything that exists in limited supply) to the lifetime of an object.
RAII guarantees that the resource is available to any function that may access the object (resource availability is a class invariant, eliminating redundant runtime tests). It also guarantees that all resources are released when the lifetime of their controlling object ends, in reverse order of acquisition. Likewise, if resource acquisition fails (the constructor exits with an exception), all resources acquired by every fully-constructed member and base subobject are released in reverse order of initialization. This leverages the core language features (object lifetime, scope exit, order of initialization and stack unwinding) to eliminate resource leaks and guarantee exception safety. Another name for this technique is Scope-Bound Resource Management (SBRM), after the basic use case where the lifetime of an RAII object ends due to scope exit.

RAII can be summarized as follows:
    encapsulate each resource into a class, where
        the constructor acquires the resource and establishes all class invariants or throws an exception if that cannot be done,
        the destructor releases the resource and never throws exceptions;
    always use the resource via an instance of a RAII-class that either
        has automatic storage duration or temporary lifetime itself, or
        has lifetime that is bounded by the lifetime of an automatic or temporary object.

Move semantics make it possible to safely transfer resource ownership between objects, across scopes, and in and out of threads, while maintaining resource safety.
*/

// Classes with open()/close(), lock()/unlock(), or init()/copyFrom()/destroy() member functions are typical examples of non-RAII classes:


#include<bits/stdc++.h>

int main(){
    std::mutex m;
 
    void bad() {
        m.lock();             // acquire the mutex
        f();                  // if f() throws an exception, the mutex is never released
        if (!everything_ok())
            return;           // early return, the mutex is never released
        m.unlock();           // if bad() reaches this statement, the mutex is released
    }
    
    void good(){
        std::lock_guard<std::mutex> lk(m); // RAII class: mutex acquisition is initialization
        f();                               // if f() throws an exception, the mutex is released
        if (!everything_ok())
            return;                        // early return, the mutex is released
    }                                      // if good() returns normally, the mutex is released
}

/*
The class lock_guard (Since c++11) is a mutex wrapper that provides a convenient RAII-style mechanism for owning a mutex for the duration of a scoped block.
When a lock_guard object is created, it attempts to take ownership of the mutex it is given. When control leaves the scope in which the lock_guard object was created, the lock_guard is destructed and the mutex is released.
The lock_guard class is non-copyable.
*/

// RAII does not apply to the management of the resources that are not acquired before use: CPU time, cores, and cache capacity, entropy pool capacity, network bandwidth, electric power consumption, stack memory.