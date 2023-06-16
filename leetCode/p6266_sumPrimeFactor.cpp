#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int sumPrimeFactor(int n){
        //cout << "SPF: "<< n << endl;
        int res=0;
        for(int i=2; i<=sqrt(n);){
            if(n%i==0){ res+=i; n=n/i;}
            else i++;
        }
        res+=n;
        return res;
    }
    int smallestValue(int n) {
        int count=n, lastCount=0;
        while(lastCount != count){
            lastCount=count;
            count = sumPrimeFactor(lastCount);
            //cout << count << " " << lastCount << endl;
        }
        return count;
    }
};