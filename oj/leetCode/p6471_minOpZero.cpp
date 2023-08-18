#include<bits/stdc++.h>
using namespace std;

class Solution {
    const int modVal = 1000000007;
public:
    int factorial(int n){
        int memo[2] = {1,1};
        for(int i=1; i<=n; i++){
            memo[i&1] = memo[(i-1)&1] * i;
        }
        return memo[n&1]%modVal;
    }
    int numberOfGoodSubarraySplits(vector<int> nums) {
        int res=0;
        for(int i=0; i<nums.size();i++){
            if(nums[i] == 1){
                if(res==0) res=1;
                for(int j=i+1; j <nums.size(); j++){
                    cout << "j:" << j << endl;
                    if(nums[j] == 1){
                        res *= (j-i);
                        cout<< res << endl;
                        //res%=modVal;

                        cout << "i: " << i << " j: " << j << " res: " << res << endl;
                        i = j-1;
                        break;
                    }
                }                
            }
        }
        return res;        
    }
};



int main(){
    Solution s;

    cout << "Number of ways: " << s.numberOfGoodSubarraySplits({1,0,0,0,0,0,1,0,1}) << endl;
}