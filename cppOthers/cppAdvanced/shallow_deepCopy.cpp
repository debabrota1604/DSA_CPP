#include <iostream>

/*
In C++, when dealing with objects and their data, the terms "shallow copy" and "deep copy" refer to how the data of one object is copied to another.

Shallow Copy: A shallow copy of an object copies the object's member variables (including pointers) to another object. However, if the object contains pointers to dynamically allocated memory (e.g., through new), only the memory addresses are copied, not the actual data. As a result, both the original and the copied objects share the same dynamically allocated memory.

Deep Copy: A deep copy, on the other hand, creates a new copy of the object along with a new copy of its dynamically allocated data. This ensures that the original and copied objects are completely independent and changes in one do not affect the other.

Here's an example to illustrate the difference between shallow copy and deep copy:
*/

class ShallowCopyExample {
public:
    int* data;

    ShallowCopyExample(int val) {
        data = new int(val);
    }

    ~ShallowCopyExample() {
        delete data;
    }

    ShallowCopyExample(const ShallowCopyExample& other) {
        data = other.data;
    }
};

class DeepCopyExample {
public:
    int* data;

    DeepCopyExample(int val) {
        data = new int(val);
    }

    ~DeepCopyExample() {
        delete data;
    }

    DeepCopyExample(const DeepCopyExample& other) {
        data = new int(*(other.data));
    }
};

int main() {
    // Shallow Copy Example
    ShallowCopyExample shallowObj1(5);
    ShallowCopyExample shallowObj2 = shallowObj1; // Shallow copy
    *shallowObj2.data = 10;

    std::cout << *shallowObj1.data << " " << *shallowObj2.data << std::endl; // Both print 10

    // Deep Copy Example
    DeepCopyExample deepObj1(5);
    DeepCopyExample deepObj2 = deepObj1; // Deep copy
    *deepObj2.data = 20;

    std::cout << *deepObj1.data << " " << *deepObj2.data << std::endl; // Prints 5 20

    return 0;
}
/*
In this example, the ShallowCopyExample class demonstrates shallow copy behavior. Both shallowObj1 and shallowObj2 share the same dynamically allocated memory, so changes in one affect the other.

The DeepCopyExample class, however, implements a deep copy. When deepObj1 is copied to deepObj2, a new copy of the data is created, resulting in independent objects.

Remember that if your class contains complex data structures or pointers to dynamically allocated memory, you need to define appropriate copy constructors and destructor or consider using the Rule of Three (or Rule of Five in C++11 and later) to ensure proper behavior when performing copy operations.
*/


/*
A default copy constrcutor is supplied by the C++ compiler whenever there's a missing user-defined copy constructor. 
The default copy constructor will copy each attribute of the class as-is (this is refered to as shallow copy). Which means, both obj1.data and obj2.data point to the same integer memory.

Problems with the default copy constructor (compiler provided - shallow copy):
1. Modification to one object is visible to the other object, which might not be desired.
2. While maintaining RAII principles, the destructors will create a problem. 
    The first object to be destroyed will be successfully destroyed, 
    but the second time when the destructor is called, there will be no valid memory reference (already freed by first destructor call to the other object).

For more info:
https://www.codementor.io/@sandesh87/the-rule-of-five-in-c-1pdgpzb04f
https://en.cppreference.com/w/cpp/language/raii
https://stackoverflow.com/questions/3106110/what-is-move-semantics

*/
