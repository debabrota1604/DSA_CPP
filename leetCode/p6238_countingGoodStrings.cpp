#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int c0, c1; vector<int> dp;
    int countStrings(int len){
        cout << "len is: " << len << endl;
        if(len==0) {return 1;}
        else if(len<0) {return 0;}
        else if(dp[len]>0){return dp[len];}
        else {dp[len]= (countStrings(len-c0) + countStrings(len-c1))%(1'000'000'000+7); return dp[len];}
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        int res=0; c0=zero, c1 = one;
        vector<int> temp (high+1, 0); dp=temp;
        countStrings(high);
        for(int iter=low; iter<=high; iter++){
            res +=dp[iter]%(1'000'000'000+7);
        }
        return res;
    }
};


int main(){
    Solution s;
    cout << s.countGoodStrings(3,3,1,1) << endl;
    cout << s.countGoodStrings(2,3,1,2) << endl;

}