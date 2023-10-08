#include<bits/stdc++.h>
using namespace std;

class Base1{
    int i;
    public:
    Base1(){cout << "Base1 Constructor" << endl; }
    ~Base1(){cout << "Base Destructor" << endl; }
};
class Base2{
    int i;
    public:
    Base2(){cout << "Base2 Constructor" << endl; }
    virtual ~Base2(){cout << "Base2 Destructor" << endl; }
};

class Derived1:public Base1{
    int i;
    public:
    Derived1(){cout << "Derived1 Constructor" << endl; }
    ~Derived1(){cout << "Derived1 Destructor" << endl; }
};
class Derived2: public Base2{
    int i;
    public:
    Derived2(){cout << "Derived2 Constructor" << endl; }
    ~Derived2(){cout << "Derived2 Destructor" << endl; }
};


int main(){

    cout << "\n\n";
    cout << "Creating and deleting object without virtual destructor" << endl;
    Derived1 *d1 = new Derived1();
    delete d1;
    cout << "\n\n";

    cout << "Creating and deleting object with virtual destructor" << endl;
    Derived2 *d2 = new Derived2();
    delete d2;
    cout << "\n\n";

    return 0;
}