#include<bits/stdc++.h>
using namespace std;

int getNthFibonacci_topDown(int n){
    if(n==0 || n==1) return n+1;
    else return getNthFibonacci_topDown(n-1) + getNthFibonacci_topDown(n-2);
}

int getNthFibonacci_bottomUp(int n){
    if(n==0 || n==1) return n+1;
    vector<int> storage (n+1, 0);
    storage.emplace_back(0);
    storage.emplace_back(1);
    for(int iter=2; iter<=n; iter++) storage[iter] = storage[iter-1] + storage[iter -2];
    return storage[n];
}

int getNthFibonacci_bottomUp_spaceOpt(int n){
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
    cout << "N-th fibonacci number for " << ip << " is: " << printFibonacciTillN(ip) << endl;
    cout << "FIbonacci series for " << ip << " elements is: "; printFibonacciTillN(ip); cout  << endl;
    return 0;
}