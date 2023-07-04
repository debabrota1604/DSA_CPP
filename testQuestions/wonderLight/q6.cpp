#include<iostream>
using namespace std;

class A{
    public:
    A(int val){cnt = val + 5; };
    A(A & val){ cnt = val.cnt +10; };
    void operator=(const A & val){ cnt = val.cnt +15; }
    int cnt;
};

int main(){
    A a(5);
    A b=a;
    cout << b.cnt << endl;
}

/*
What is the putput of the below program
A. 10
B. 15
C. 20
D. 30

Correct Answer: C
*/