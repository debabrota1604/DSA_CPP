#include<iostream>
using namespace std;

bool foo(double arg){
    return arg != arg;
}

int main(){
    // unsigned short i = 65535U;
    // i++;
    // cout << i << endl;
    // cout << foo(5) << endl;

    int x=!!5; cout << x << endl;

    return 0;
}