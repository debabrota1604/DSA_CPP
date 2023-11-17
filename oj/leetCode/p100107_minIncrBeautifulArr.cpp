#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    long long minIncrementOperations2(vector<int>& nums, int k) {
        int tempMax, res=0;
        for(int iter=2; iter<nums.size(); iter+=3){
            // compute Max pos and val


            if(tempMax <k){
                nums[]
                res += k-tempMax;
            }
        }
        return tempMax;
    }

    long long solve(vector<int>& nums, int k, int index, int tempMinOp){
        if(index == nums.size()) return INT_MAX;

        long long cost = solve(nums, k, index+1, tempMinOp); //ignore smaller value to be handled by next recursion

        if(max(nums[index-1], max(nums[index], nums[index+1])) <k){ //consider smaller value
            nums[index] += k-nums[index];
            cost = min(cost, solve(nums, k, index+1, tempMinOp + k -nums[index]));
            nums[index] -= k-nums[index];
        }
        return cost;
    }

    long long minIncrementOperations(vector<int>& nums, int k) {
        return solve(nums, k, 1, 0);
    }
};