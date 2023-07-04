#include<iostream>
using namespace std;

class Vehicle{
    public:
    void Steer(){ cout << "Steering Vehicle" << endl;}
};

class Car: public Vehicle{
    public:
    virtual void Steer(){ cout << "Steering Car" << endl; }
};

int main(){
    Vehicle *v1 = new Car();
    v1->Steer();
}

/*
Output of the code:
A. Steering Vehicle
B. Steering Car
C. Program Crashes
D. Compilation Error

Correct Answer: A

*/