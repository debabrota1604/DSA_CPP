/*
Friend Function: 

In C++, a friend function is a function that is granted access to the private and protected members of a class, even though it is not a member of that class. It is declared with the friend keyword within the class definition.

Here are some key points to understand about friend functions:

1. Accessing Private Members: A friend function can access private and protected members of the class, just like the member functions of the class.

2. Declaration Inside Class: Friend functions are declared inside the class definition but defined outside the class, usually in the same source file.

3. Not Inherited: Friend functions are not inherited, meaning that they are not accessible in derived classes.

5. Usage: Friend functions are often used in scenarios where you want to provide access to certain functions from outside the class 
    to manipulate its private data. However, they should be used judiciously to maintain encapsulation and prevent misuse.

6. Friendship Is Not Symmetric: If class A declares class B as its friend, it does not mean that class B automatically considers 
    class A as its friend. Friendship is not reciprocal.

*/




class MyClass1 {
private:
    int privateMember;

public:
    MyClass1() : privateMember(0) {}

    friend void friendFunction(MyClass1& obj);
};

void friendFunction(MyClass1& obj) {
    obj.privateMember = 42; // Accessing private member through the friend function
}


/*
Friend Classes:
A friend class is a class that is declared as a friend inside another class. It has access to the private and protected members of the class that declares it as a friend. Friend classes can access the members of the declaring class, similar to the way member functions can. Friend classes can be useful when you want to grant access to a group of related classes.

*/

class MyClass {
private:
    int privateMember;

public:
    MyClass() : privateMember(0) {}

    friend class FriendClass; // FriendClass has access to MyClass's private members
};

class FriendClass {
public:
    void manipulatePrivateMember(MyClass& obj) {
        obj.privateMember = 42; // Accessing private member through the friend class
    }
};


/*
It's essential to use friend functions carefully and only when necessary. Overusing friend functions can undermine the encapsulation 
principle of object-oriented programming and make the code less maintainable. Always prefer to access class members through member 
functions whenever possible, and only use friend functions when there is a clear need to access private or protected data from outside the class.

*/
