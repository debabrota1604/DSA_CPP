#include<bits/stdc++.h>
using namespace std;

int getNthFibonacci(int n){
    int last1=1, last2=0, res;
    if(n<=0) return last2;
    if(n==1) return last1;
    for(int i=2; i<n; i++){ res =last1+last2; last2 =last1; last1 =res; }
    return res;
}

void printFibonacciTillN(int n){
    int last1=1, last2=0, res;
    if(n<0) return;
    for(int i=0; i<n; i++){
        if(i==0) cout << "0 ";
        else if(i==1) cout << "1 ";
        else {res =last1+last2; last2 =last1; last1 =res; cout << res << " ";}
    }
}


int main(){
    int ip; cin >> ip;
    cout << "N-th fibonacci number for " << ip << " is: " << getNthFibonacci(ip) << endl;
    cout << "FIbonacci series for " << ip << " elements is: "; printFibonacciTillN(ip); cout  << endl;
    return 0;
}