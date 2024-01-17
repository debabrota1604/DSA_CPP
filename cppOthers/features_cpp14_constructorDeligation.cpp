#include <iostream>
using namespace std;

/*
Constructor delegation in C++ allows one constructor of a class to call another constructor in the same class. This feature is helpful when you want to avoid code duplication in multiple constructors by having one constructor initialize common members and then delegate to other constructors for additional, specific initialization.

Here's a C++14 code example that demonstrates how constructor delegation works and provides explanations:
*/

class MyClass {
public:
    // Constructor 1: Default Constructor
    MyClass() {
        id_ = 0;
        name_ = "Default";
        std::cout << "Default Constructor Called" << std::endl;
    }

    // Constructor 2: Constructor with Parameters
    MyClass(int id, const std::string& name) {
        id_ = id;
        name_ = name;
        std::cout << "Parameterized Constructor Called" << std::endl;
    }

    // Constructor 3: Constructor with a single parameter
    MyClass(int id) {
        id_ = id;
        name_ = "Unnamed";
        std::cout << "Constructor with ID Called" << std::endl;
    }

    void Display() const {
        std::cout << "ID: " << id_ << ", Name: " << name_ << std::endl;
    }

private:
    int id_;
    std::string name_;
};

// With Constructor Deligation
class MyClass_CD {
public:
    // Constructor 1: Default Constructor
    MyClass_CD() : MyClass_CD(0, "Default") {
        std::cout << "Default Constructor Called" << std::endl;
    }

    // Constructor 2: Constructor with Parameters
    MyClass_CD(int id, const std::string& name) : id_(id), name_(name) {
        std::cout << "Parameterized Constructor Called" << std::endl;
    }

    // Constructor 3: Constructor with a single parameter
    MyClass_CD(int id) : MyClass_CD(id, "Unnamed") { //cals Constructor internally
        std::cout << "Constructor with ID Called" << std::endl;
    }

    void Display() const {
        std::cout << "ID: " << id_ << ", Name: " << name_ << std::endl;
    }

private:
    int id_;
    std::string name_;
};

void notConstructorDeligation() {
    // Using Constructor 1: Default Constructor
    MyClass obj1;
    obj1.Display();
    std::cout << std::endl;

    // Using Constructor 2: Constructor with Parameters
    MyClass obj2(1, "Alice");
    obj2.Display();
    std::cout << std::endl;

    // Using Constructor 3: Constructor with a single parameter
    MyClass obj3(2);
    obj3.Display();
}

void withConstructorDeligation() {
    // Using Constructor 1: Default Constructor
    MyClass_CD obj1;
    obj1.Display();
    std::cout << std::endl;

    // Using Constructor 2: Constructor with Parameters
    MyClass obj2(1, "Alice");
    obj2.Display();
    std::cout << std::endl;

    // Using Constructor 3: Constructor with a single parameter
    MyClass obj3(2);
    obj3.Display();
}

int main(){
    cout << "Result without constructor deligation: " << endl;
    notConstructorDeligation();

    /*
    Result without constructor deligation: 
    Default Constructor Called
    ID: 0, Name: Default

    Parameterized Constructor Called
    ID: 1, Name: Alice

    Constructor with ID Called
    ID: 2, Name: Unnamed
    */

    cout << "\n\nResult with constructor deligation: " << endl;
    withConstructorDeligation();

    /*
    Result with constructor deligation: 
    Parameterized Constructor Called
    Default Constructor Called
    ID: 0, Name: Default

    Parameterized Constructor Called
    ID: 1, Name: Alice

    Constructor with ID Called
    ID: 2, Name: Unnamed
    */
}




/*
In this code:

We define a class MyClass with three constructors:

Constructor 1: The default constructor initializes id_ to 0 and name_ to "Default" and then delegates to Constructor 2.
Constructor 2: A parameterized constructor that initializes id_ and name_.
Constructor 3: A constructor with a single parameter for id_, which delegates to Constructor 2 with a default name "Unnamed."
In the main function, we create objects of MyClass using various constructors:

obj1 uses the default constructor.
obj2 uses the parameterized constructor.
obj3 uses the constructor with a single parameter.
When you run this code, you'll see that constructor delegation allows you to reuse initialization logic while providing flexibility for different constructors. It's particularly useful when you have multiple constructors that share common initialization steps.

*/