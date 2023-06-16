#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isPrime(int num){
        for(int i=2; i<= num/2; i++)
            if(num%i==0) return false;
        return true;
    }

    bool isGoodNum(int num){
        if (num <1) return false;

        for(int i=2; i<num/2; i++)
            if(num%i == 0 && i!= num/i)
                if(isPrime(i) && isPrime(num/i)){ cout << num << " is a good number as " << i << "*" << num/i << endl; return true;}
        return false;
    }
    public:

    int minMoves(int query){
        
        for(int i=0; ;i++){
            if (isGoodNum(query - 2*i) || isGoodNum(query + 2*i)) return i;
        }
        
    }
};


int main(){
    Solution s; int inp; cin >> inp;


    cout << s.minMoves(inp) << " is the step count to find the good number." << endl;


}