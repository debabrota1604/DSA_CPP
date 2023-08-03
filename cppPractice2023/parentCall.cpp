#include<iostream>
using namespace std;

class A{
    public:
    void foo(){cout << "Foo()" << endl;}
};

class B: private A{
    private:
    void foo(){
        A::foo();
    }
};

int main(){
    if(1==1) cout << "True\n";
    B b;
}