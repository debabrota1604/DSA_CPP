#include<bits/stdc++.h>
using namespace std;

int euclideanGCD(int x, int y){
    if(!x) return y;
    if(!y) return x;

    if(x==y) return x;
    if(x>y) return euclideanGCD(x-y,y);
    else    return euclideanGCD(x,y-x);
}

int euclideanGCDModulo(int x, int y){
    return y==0 ? x:gcd(y,x%y);
}

int gcdIterative(int x, int y){
    int temp;
    //use modulo and loop until y is 0
    while(y){ temp = x%y; x=y; y=temp;}
    return x;
}

int gcdExtended(int a, int b, int &x, int &y)
{
    if(!a){x = 0; y = 1; return b;} //base case
 
    int x1, y1, res = gcdExtended(b%a, a, x1, y1);
 
    // Update x and y using results of recursive call
    x = y1 - (b/a) * x1;  y = x1;
 
    return res;
}

#define MOD 1000000007  
 
long long  fast_exp(int base, int exp)  
{      
    long long res=1;
    while(exp>0) {         
        if(exp%2==1) res=(res*base)%MOD;         
        base=(base*base)%MOD; exp/=2; 
    }      
    return res%MOD; 
} 

int main(){
    int a=15,b=10, x,y,z=1e9+7;
    cout << gcdExtended(a,b,x,y) << endl;
    cout << z << endl;
    cout << "Extended GCD multipliers: " << x << " " << y << endl;
    
  
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;

}