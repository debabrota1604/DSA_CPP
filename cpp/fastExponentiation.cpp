#include<iostream>
using namespace std;

// This algorithm runs in O(log (exponent)) time.
// Idea is to use the idea a^10 = a^5*a^5 and a^11 = a^5*a^5*a. 
// Distinguish even and odd cases and use recursion for sub-powers

unsigned long long fastExponentiation (int base, int exponent){
    if(exponent ==0) return 1;
    if(exponent ==1) return base;
    cout << "Exponent: " << exponent << endl;

/*
    // Long code
    int res=1;
    if(exponent&1 ==0){
        // Exponent is even number
        res = fastExponentiation(base, exponent/2) * fastExponentiation(base, exponent/2);
    }
    else{
        res *= fastExponentiation(base, exponent/2) * fastExponentiation(base, exponent/2) * res;
    }

*/
    // Short code, see above commented code for explanation.
    auto res = fastExponentiation(base, exponent/2);
    res *= res; //computes square
    if(exponent&1) res*= base; // computes square *base

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