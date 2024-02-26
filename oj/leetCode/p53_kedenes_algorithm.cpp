#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_so_far, max_ending_here;
        max_so_far = INT_MIN;
        max_ending_here =0;
        for(auto num:nums){
            max_ending_here += num;
            if(max_ending_here > max_so_far) max_so_far = max_ending_here;
            max_ending_here <0 ? max_ending_here =0 :1;
        }
        return max_so_far;
    }
};