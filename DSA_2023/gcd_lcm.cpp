#include<bits/stdc++.h>
using namespace std;

int max(int x, int y){
    return x>y ? x:y;
}

int min(int x, int y){
    return x<y ? x:y;
}

int gcd(int x, int y){
    int maxDivisor=1;
    for(int iter=1; iter<max(x,y); iter++){
        if(x%maxDivisor==0 && y%maxDivisor==0) maxDivisor = iter;
    }
    return maxDivisor;
}

int lcm(int x, int y){
    int minMultiple=max(x,y);
    for(int iter = minMultiple; iter <=x*y; iter++){
        if(minMultiple%x==1 && minMultiple%y==1){
            minMultiple = iter; break;
        }
    }
    return minMultiple;
}


int main(){
    int x,y; cin >> x >> y;
    cout << "GCD: " << gcd(x,y) << endl;
    cout << "LCM: " << lcm(x,y) << endl;


    return 0;
}