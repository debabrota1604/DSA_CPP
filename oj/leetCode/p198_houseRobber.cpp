#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int solve(vector<int> inp, int lastIndex){
        if(lastIndex < 0) return 0;
        else return max(solve(inp,lastIndex-1), solve(inp, lastIndex-2) + inp[lastIndex]);
    }
    int rob(vector<int>& nums) {
        //return solve(nums, nums.size()-1);
        if(nums.size() ==1) return nums[0];
        int prev1, prev2, memory[2] = {nums[0], max(nums[0], nums[1])};
        
        for(int i=2; i< nums.size(); i++){
            prev1=(i-1)%2;
            prev2=(i-2)%2;
            memory[i%2] = max(memory[prev1], memory[prev2] + nums[i]);
        }
        return memory[(nums.size()-1)%2];
    }
};
