#include<bits/stdc++.h>
using namespace std;

// Step 1: Find the max bitwise-AND value K.
// Step 2: Find the max length that generates K.

// Step 1: max Bitwise k is only achievable when all elements are same and max-element.
// Step 2: choose the max element. Find the maximum longest contiguous array containing all same elements.


class Solution {
public:

    int longestSubarray(vector<int>& nums) {
        int len=0,maxLen=0, maxEl = *max_element(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == maxEl) len++;
            else len=0;
            if(len>maxLen) maxLen = len;
        }
        return maxLen;
    }
};

int main(){

}