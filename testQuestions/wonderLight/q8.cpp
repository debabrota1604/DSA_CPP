#include<iostream>
using namespace std;

class A{
    private:
    int * value;

    public:
    A(){ value = new int; }
    void set_value(int v){ *value = v; }
    void show_data(){ cout << "Value = " << *value << endl; }
    A(A& sample){ value = sample.value; }
    ~A(){ }
    
};


int main(){
    A a;
    a.set_value(100);
    A b=a;
    b.set_value(200);
    a.show_data();
    return 0;



}
/*
Output should be 
A. 100
B. 200
C. 300
D. None of the above

Correct Answer: B
*/