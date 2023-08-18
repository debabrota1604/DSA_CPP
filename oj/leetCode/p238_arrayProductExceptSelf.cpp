#include<bits/stdc++.h>
using namespace std;

/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.
*/


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res (nums.size(),1), res2 (nums.size(),1);
        for(int i=1; i<nums.size(); i++){
            res[i] *= res[i-1] * nums[i-1];
        }
        for(int i=nums.size() -2; i >=0; i--){
            res2[i] *= res2[i+1] * nums[i+1];
            res[i] = res[i] * res2[i];
        }
        return res;
    }
};