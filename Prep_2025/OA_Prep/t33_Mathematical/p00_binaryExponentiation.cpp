#include <bits/stdc++.h>
using namespace std;

long long power_recursive(long long n, long long p){
    if (p==0) return 1;

    long long res = power_recursive(n, p/2);

    if (p%2) return res*res*n;
    else return res*res;
}

long long power_iterative(long long n, long long p){
    long long res =1;
    while(p) {
        if (p&1) res=res*n; //if p is odd, multiply n with res
        n=n*n;
        p>>=1; //divide by 2
    }
    return res;
}

int main(){
    cout << power_recursive(2, 12) << "\n";
    cout << power_iterative(2, 12) << "\n";
    return 0;
}