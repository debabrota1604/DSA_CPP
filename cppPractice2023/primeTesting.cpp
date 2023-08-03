#include<bits/stdc++.h>
using namespace std;

bool isPrime(int num){// returns true for a prime
    for(auto iter=2;iter<=num/2;iter++){
        if((int(num/iter) * iter) == num){ cout << "breaking :" << iter << endl; return false; }
    }
    return true;
}

int main(){
    int input; cin >> input;
    cout << isPrime(input) << endl;



    return 0;
}