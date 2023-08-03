//Object-Oriented Programming (OOP) concepts in C++ are essential principles that help in designing and structuring code. The key OOP concepts in C++ are:

// 1. Class and Object:
// A class is a blueprint for creating objects, and an object is an instance of a class. It encapsulates data and functions that operate on that data.

#include <iostream>
using namespace std;

class Car {
public:
    string make;
    string model;

    void displayInfo() {
        cout << "Make: " << make << ", Model: " << model << endl;
    }
};

int main() {
    Car car1;
    car1.make = "Toyota";
    car1.model = "Corolla";
    car1.displayInfo();

    Car car2;
    car2.make = "Honda";
    car2.model = "Civic";
    car2.displayInfo();

    return 0;
}

// 2. Abstraction:
// Abstraction allows hiding the implementation details of an object, exposing only essential features. It helps manage complexity and allows users to focus on high-level functionality.

#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() = 0; // Pure virtual function for abstraction
};

class Circle : public Shape {
public:
    void draw() {
        cout << "Drawing a circle" << endl;
    }
};

class Square : public Shape {
public:
    void draw() {
        cout << "Drawing a square" << endl;
    }
};

int main() {
    Circle circle;
    Square square;

    Shape* shape1 = &circle;
    Shape* shape2 = &square;

    shape1->draw();
    shape2->draw();

    return 0;
}


// 3. Encapsulation:
// Encapsulation bundles data and methods together, restricting access to the internal state of an object. It promotes data hiding and prevents unauthorized access.

#include <iostream>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    double balance;

public:
    BankAccount(string accNum, double initialBalance) {
        accountNumber = accNum;
        balance = initialBalance;
    }

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    double getBalance() {
        return balance;
    }
};

int main() {
    BankAccount account("123456", 1000.0);
    account.deposit(500.0);
    account.withdraw(200.0);

    cout << "Account Balance: $" << account.getBalance() << endl;

    return 0;
}


// 4. Inheritance:
// Inheritance enables creating a new class (derived class) from an existing class (base class), inheriting its properties and behaviors. It supports code reuse and polymorphism.

#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() {
        cout << "Drawing a shape" << endl;
    }
};

class Circle : public Shape {
public:
    void draw() {
        cout << "Drawing a circle" << endl;
    }
};

class Square : public Shape {
public:
    void draw() {
        cout << "Drawing a square" << endl;
    }
};

int main() {
    Circle circle;
    Square square;

    Shape* shape1 = &circle;
    Shape* shape2 = &square;

    shape1->draw(); // Output: Drawing a circle
    shape2->draw(); // Output: Drawing a square

    return 0;
}


// 5. Polymorphism:
// Polymorphism allows objects of different classes to be treated as objects of a common base class. It provides a way to perform different actions based on the actual type of the object at runtime.

#include <iostream>
using namespace std;

class Animal {
public:
    virtual void makeSound() {
        cout << "Animal sound" << endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() {
        cout << "Woof!" << endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() {
        cout << "Meow!" << endl;
    }
};

int main() {
    Animal* animals[2];
    animals[0] = new Dog();
    animals[1] = new Cat();

    for (int i = 0; i < 2; i++) {
        animals[i]->makeSound(); // Output: Woof!   Meow!
    }

    return 0;
}

// 6. Polymorphic Behavior using Virtual Functions:
// Virtual functions allow late binding, ensuring the appropriate function is called based on the object's actual type.

#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() {
        cout << "Drawing a shape" << endl;
    }
};

class Circle : public Shape {
public:
    void draw() {
        cout << "Drawing a circle" << endl;
    }
};

class Square : public Shape {
public:
    void draw() {
        cout << "Drawing a square" << endl;
    }
};

int main() {
    Circle circle;
    Square square;

    Shape* shape1 = &circle;
    Shape* shape2 = &square;

    shape1->draw(); // Output: Drawing a circle
    shape2->draw(); // Output: Drawing a square

    return 0;
}


/*
These are the key Object-Oriented Programming (OOP) concepts in C++ with code examples for each. OOP concepts help in creating modular, maintainable, and scalable code by using abstraction, encapsulation, inheritance, and polymorphism.
*/