#include<bits/stdc++.h>
using namespace std;

// An integer n is strictly palindromic if, for every base b between 2 and n - 2 (inclusive),
// the string representation of the integer n in base b is palindromic.
// Given an integer n, return true if n is strictly palindromic and false otherwise.
// A string is palindromic if it reads the same forward and backward.


class Solution {
public:
    bool isPalin(string st){
        bool res = true;
        for(int iter=0; iter<st.size()/2; iter++){
            if(st[iter] == st[st.size()-iter-1]) res *=true;
            else res*= false;
        }
        return res;
    }
    string representRthBase(int num, int radix){
        string res="";
        while(num>0){
            res = to_string(num%radix) + res;
            num = num/radix;
        }
        return res;
    }

    bool isStrictlyPalindromic(int n) {
        bool res=true;
        for(int iter=2; iter<n-1; iter++){
            res *=isPalin(representRthBase(n, iter));
        }
        return res;
    }
};

int main(){
    Solution s;
    cout << s.isStrictlyPalindromic(0) << endl;



    return 0;
}