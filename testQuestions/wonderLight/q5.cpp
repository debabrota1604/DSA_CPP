#include<iostream>
using namespace std;


class A{
    public:
    virtual void display() = 0;
};

void A::display(){ cout << "hello world."; }

class B : public A{
    public:
    void display(){
        A::display();
        cout << "i am here.";
    };
};

int main(){
    B a;
    a.display();
    return 0;
}

/*
Output will be:
A. Compilation Error
B. Runtime Error
C. i am here
D. hello world. i am here.

Correct Answer: D
*/