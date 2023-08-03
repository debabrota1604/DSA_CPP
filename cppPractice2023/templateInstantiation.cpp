#include<iostream>
using namespace std;

template<typename A> void foo(A arg){ cout << "generic" <<endl;}
template<> void foo(int arg){ cout << "int" <<endl;}
template<> void foo(double arg){ cout << "double" <<endl;}

int main(){
    foo(char(42));

    return 0;
}