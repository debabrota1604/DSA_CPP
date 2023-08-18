#include<bits/stdc++.h>
using namespace std;

/*
An element x of an integer array arr of length m is dominant if freq(x) * 2 > m, where freq(x) is the number of occurrences of x in arr. 
Note that this definition implies that arr can have at most one dominant element.

You are given a 0-indexed integer array nums of length n with one dominant element.

You can split nums at an index i into two arrays nums[0, ..., i] and nums[i + 1, ..., n - 1], but the split is only valid if:

0 <= i < n - 1
nums[0, ..., i], and nums[i + 1, ..., n - 1] have the same dominant element.
Here, nums[i, ..., j] denotes the subarray of nums starting at index i and ending at index j, both ends being inclusive. 
Particularly, if j < i then nums[i, ..., j] denotes an empty subarray.

Return the minimum index of a valid split. If no valid split exists, return -1.

*/


class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        
        //Step1: Compute dominant element and the frequency
        unordered_map<int,int> fq;
        for(auto i: nums) fq[i]++;
        
        auto f = fq[nums[0]];
        int domEl, domElFreq = INT_MIN;
        for(auto i: fq){
            if(i.second > domElFreq){
                domElFreq = i.second;
                domEl = i.first;
            } 
        }        
        
        //Step2: Traverse each middle index from left to right and check for valid split. If end reached, return -1;
        int pastOccurence=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == domEl) pastOccurence++;
            
            int lsize=i+1, rsize=nums.size()-i-1;
            bool ldominant = pastOccurence*2 >lsize, rdominant = (domElFreq - pastOccurence)*2 >rsize;
            
            if(ldominant && rdominant) return i;            
        }
        return -1;
    }
};

int main(){


    return 0;
}