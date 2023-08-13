#include <iostream>

/*
To design a class that ensures only one instance of the object is created and  returned every time, you can implement the Singleton design pattern in C++. The Singleton pattern restricts the instantiation of a class to only one object and provides a global point of access to that object.

Here's a simple implementation of a Singleton class in C++:
*/

class Singleton {
private:
    // Private constructor to prevent external instantiation
    Singleton() {}

    // Private static instance variable to hold the single instance
    static Singleton* instance;

public:
    // Public static method to get the single instance
    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }

    // Add any other methods or members as needed

    // Optional: Delete the copy constructor and assignment operator to prevent cloning or copying
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
};

// Initialize the static instance variable to nullptr
Singleton* Singleton::instance = nullptr;

int main() {
    // Create objects using the getInstance() method
    Singleton* obj1 = Singleton::getInstance();
    Singleton* obj2 = Singleton::getInstance();

    // Both obj1 and obj2 will point to the same single instance of the Singleton class
    std::cout << "Memory address of obj1: " << obj1 << std::endl;
    std::cout << "Memory address of obj2: " << obj2 << std::endl;

    return 0;
}

/*
In this implementation, the Singleton class has a private constructor, which means objects cannot be directly instantiated from outside the class. Instead, it provides a public static method getInstance() that returns the single instance of the class. The first time getInstance() is called, it creates a new instance of the Singleton class. On subsequent calls, it returns the same instance that was created earlier.

By using this pattern, you can ensure that only one instance of the class is created, and every time you request an object, you'll get the same instance.
*/
