#include<iostream>
using namespace std;

unsigned long long fastExponentiation (int base, int exponent){
    if(exponent==1) return base;
    cout << "Exponent: " << exponent << endl;

/*
int res=1;
    if(exponent&1 ==0){
        // Exponent is even number
        res = fastExponentiation(base, exponent/2) * fastExponentiation(base, exponent/2);
    }
    else{
        res *= fastExponentiation(base, exponent/2) * fastExponentiation(base, exponent/2) * res;
    }

*/
    auto res = fastExponentiation(base, exponent/2);
    res *= res;
    if(exponent&1) res*= base;

    return res;
}

int main(){
    int base, exponent;
    base = 2;
    cout << "Enter exponent for power of 2: ";
    cin >> exponent;
    unsigned long long result = fastExponentiation(base, exponent);


    cout << base << " to the power " << exponent << ": " << result << endl;
}