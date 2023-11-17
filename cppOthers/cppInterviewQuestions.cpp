/*
 Structure vs class in C++
In C++, a structure is same as class except the following differences: 
    Members of a class are private by default and members of struct are public by default.
    When deriving a struct from a class/struct, default access-specifier for a base class/struct is public. And when deriving a class, default access specifier is private. 



Malloc() vs new / Delete vs Free:
Following are the differences between malloc() and operator new.  
    new is an operator, while malloc() is a function.
    new returns exact data type, while malloc() returns void *.
    new calls constructors( class instances are initialized and deinitialized automatically), while malloc() does not( classes won’t get initialized or deinitialized automatically
    Syntax: 
    int *n = new int(10); // initialization with new()
    str = (char *) malloc(15); //malloc()
    free( ) is used on resources allocated by malloc( ), or calloc( ) in C 
Delete is used on resources allocated by new in C++  



Inline Functions:
C++ provides an inline functions to reduce the function call overhead. Inline function is a function that is expanded in line when it is called. When the inline function is called whole code of the inline function gets inserted or substituted at the point of the inline function call. This substitution is performed by the C++ compiler at compile time. Inline function may increase efficiency if it is small. 

The syntax for defining the function inline is: 
    inline return-type function-name(parameters) 
    { 
    // function code 
    } 
Remember, inlining is only a request to the compiler, not a command. Compiler can ignore the request for inlining. 




Friend class and function in C++:
A friend class can access private and protected members of other class in which it is declared as friend. It is sometimes useful to allow a particular class to access private members of other class. For example a LinkedList class may be allowed to access private members of Node. 

Friend Function Like friend class, a friend function can be given a special grant to access private and protected members. A friend function can be: 
    a) A method of another class 
    b) A global function 

Important points about friend functions and classes: 
    1) Friends should be used only for a limited purpose. too many functions or external classes are declared as friends of a class with protected or private data, it lessens the value of encapsulation of separate classes in object-oriented programming. 
    2) Friendship is not mutual. If class A is a friend of B, then B doesn’t become a friend of A automatically. 
    3) Friendship is not inherited (See this for more details) 
    4) The concept of friends is not there in Java. 




Function overloading VS Operator Overloading:
Function overloading is a feature in C++ where two or more functions can have the same name but different type of parameters and  different number of parameters. 
Note: Overloading of functions with different return types are not allowed. 
Operator overloading allows us to make operators work for user-defined classes. For example, we can overload an operator ‘+’ in a class like String so that we can concatenate two strings by just using +. 
Other example classes where arithmetic operators may be overloaded are Complex Number, Fractional Number, Big Integer, etc. 




Copy Constructor
A copy constructor is a member function that initializes an object using another object of the same class. A copy constructor has the following general function prototype: ClassName (const ClassName &old_obj); 
    Point(int x1, int y1) { x = x1; y = y1; } 

    // Copy constructor 
    Point(const Point &p2) {x = p2.x; y = p2.y; } 

When is copy constructor called? 
In C++, a Copy Constructor may be called in the following cases: 
    When an object of the class is returned by value.
    When an object of the class is passed (to a function) by value as an argument.
    When an object is constructed based on another object of the same class.
    When compiler generates a temporary object.

Can we make copy constructor private? 
    Yes, a copy constructor can be made private 



What is Static Member?
Static is a keyword in C++ used to give special characteristics to an element. Static elements are allocated storage only once in a program lifetime in static storage area. And they have a scope till the program lifetime. Static Keyword can be used with following, 

Interesting facts about Static Members Functions  in C++ 
    static member functions do not have this pointer.
    A static member function cannot be virtual
    Member function declarations with the same name and the name parameter-type-list cannot be overloaded if any of them is a static member function declaration.
    static member function can not be declared const, volatile, or const volatile.




What is a virtual destructor?
When destroying instances or objects of a derived class using a base class pointer object, a virtual destructor is invoked to free up memory space allocated by the derived class object or instance.

Virtual destructor guarantees that first the derived class’ destructor is called. Then the base class’s destructor is called to release the space occupied by both destructors in the inheritance class which saves us from the memory leak. It is advised to make your destructor virtual whenever your class is polymorphic.



Is destructor overloading possible? If yes then explain and if no then why?
The simple answer is NO we cannot overload a destructor. It is mandatory to only destructor per class in C++. Also to mention, Destructor neither take arguments nor they have a parameter that might help to overload.



What is an abstract class and when do you use it?
An abstract class is a class that is specifically designed to be used as a base class. An abstract class contains at least one pure virtual function. You declare a pure virtual function by using a pure specifier(= 0) in the declaration of a virtual member function in the class declaration

You cannot use an abstract class as a parameter type, a function return type, or the type of an explicit conversion, nor can you declare an object of an abstract class. However, it can be used to declare pointers and references to an abstract class. 

An abstract class is used if you want to provide a common, implemented functionality among all the implementations of the component. Abstract classes will allow you to partially implement your class, whereas interfaces would have no implementation for any members whatsoever. In simple words, Abstract Classes are a good fit if you want to provide implementation details to your children but don’t want to allow an instance of your class to be directly instantiated.






What is the main use of the keyword “Volatile”?
Just like its name, things can change suddenly and unexpectantly; So it is used to inform the compiler that the value may change anytime. Also, the volatile keyword prevents the compiler from performing optimization on the code. It was intended to be used when interfacing with memory-mapped hardware, signal handlers, and machine code instruction.
More info: https://www.geeksforgeeks.org/understanding-volatile-qualifier-c-set-1-introduction/





What is a mutable storage class specifier? How can they be used?
Just like its name, the mutable storage class specifier is used only on a class data member to make it modifiable even though the member is part of an object declared as const. Static or const, or reference members cannot use the mutable specifier. When we declare a function as const, this pointer passed to the function becomes const.





Define namespace in C++.
Namespaces enable us to organize named items that would otherwise have global scope into smaller scopes, allowing us to give them namespace scope. This permits program parts to be organized into distinct logical scopes with names. The namespace provides a place to define or declare identifiers such as variables, methods, and classes. 

Or we could say that A namespace is a declarative zone that gives the identifiers (names of types, functions, variables, and so on) within it a scope. Namespaces are used to arrange code into logical categories and to avoid name clashes, which might happen when you have many libraries in your code base.
More info: https://www.geeksforgeeks.org/namespace-in-c/




What is ‘this‘ pointer in C++?
this pointer enables every object to have access to its own address through an essential pointer. All member functions take this pointer as an implicit argument. this pointer may be used to refer to the calling object within a member function. 

this pointer is used to pass an object as a parameter to another method.
Each object gets its own copy of the data member.
this pointer is used to declare indexers.

*/