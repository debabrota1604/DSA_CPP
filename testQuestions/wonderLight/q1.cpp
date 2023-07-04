/*
Copy constructor is called when
A. Copying one object to another
B. Call by value of object to a function
C. Return by value of and object from a function
D. All of the above

Correct Answer: D

*/
#include<iostream>
using namespace std;

class A{
    int a;
    char c;
    public:
    A(){ a=0; c ='c'; }
    A(A& b){a = b.a; c = b.c; cout << "Copy constructor called!\n"; }
    void setInt(int i){ a = i; }
    void setChar(char ch){ c = ch; }
    void print(){cout << "Int: " << a << " Char: " << c << endl; }
};

void fun1(A a){
    cout << "Within fun1\n";
    a.print();
}

A fun2(A a){
    cout << "Within fun2 returning obj\n";
    a.setChar('f');
    a.print();
    return a;
}

int main(){
    A obj;
    obj.setInt(5);
    obj.print();

    cout << "Declaring new object from obj: ";
    A copyObj = obj;
    copyObj.print();

    cout << "Passing obj to fun1";
    fun1(obj);

    cout << "Returning obj test";
    obj = fun2(obj);
    cout << "After returning to main(): ";
    obj.print();

    return 0;
}