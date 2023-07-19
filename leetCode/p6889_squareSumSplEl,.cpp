#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int len = nums.size(), res=0;
        
        // Check for speciality condition for each element and update result
        for(int i=0; i<len; i++){
            if(len%(i+1) ==0) res += nums[i]*nums[i];
        }
        return res;
    }
};