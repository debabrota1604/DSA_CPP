#include <bits/stdc++.h>;
using namespace std;

const int mod = 1e9 + 7;

long long power_mod(long long a, long long b){
    long long res = 1;
    while (b) {
        if (b & 1) // If b is odd, multiply a with res
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int main(){
    cout << "2^42 mod " << mod << ": " << power_mod(2, 42) << "\n";
    return 0;
}