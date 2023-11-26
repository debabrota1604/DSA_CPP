#include<bits/stdc++.h>
using namespace std;

// Some potential virtual function irrespective of the slower execution:

/* 1. Polymorphism and Inheritance: */
class Shape {
public:
    virtual void draw() const = 0;
};

class Circle : public Shape {
public:
    void draw() const override {
        // Draw circle
    }
};

class Square : public Shape {
public:
    void draw() const override {
        // Draw square
    }
};


/* 2. Factory Pattern */

class Animal {
public:
    virtual void speak() const = 0;
};

class Dog : public Animal {
public:
    void speak() const override {
        // Bark
    }
};

class Cat : public Animal {
public:
    void speak() const override {
        // Meow
    }
};

class AnimalFactory {
public:
    static Animal* createAnimal(int type);
};

/* 3. Observer Pattern */

class Observer {
public:
    virtual void update() = 0;
};

class ConcreteObserver : public Observer {
public:
    void update() override {
        // React to changes
    }
};

class Subject {
private:
    std::vector<Observer*> observers;

public:
    void addObserver(Observer* observer) {
        observers.push_back(observer);
    }

    void notifyObservers() {
        for (Observer* observer : observers) {
            observer->update();
        }
    }
};


/* 4. Template Metaprogramming */

template <typename T>
T add(const T& a, const T& b) {
    return a + b;
}

template <>
std::string add(const std::string& a, const std::string& b) {
    return a + " " + b;
}


/* 5. Smart Pointers: */

std::shared_ptr<Base> ptr = std::make_shared<Derived>();


/* 6. Resource Management: */

class File {
private:
    FILE* file;

public:
    explicit File(const char* filename) {
        file = fopen(filename, "r");
        if (!file) {
            // Handle error
        }
    }

    ~File() {
        fclose(file);
    }
};


/* 7. Function Pointers:*/

void operation1() {
    // Perform operation 1
}

void operation2() {
    // Perform operation 2
}

using OperationFunction = void (*)();

void executeOperation(OperationFunction operation) {
    operation();
}

















