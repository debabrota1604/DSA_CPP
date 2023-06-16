#include<bits/stdc++.h>
using namespace std;

// Problem
// There is an integer array nums sorted in ascending order (with distinct values).
// Prior to being passed to your function, nums is possibly rotated at an unknown 
// pivot index k (1 <= k < nums.length) such that the resulting array is 
// [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). 
// For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

// Given the array nums after the possible rotation and an integer target, return 
// the index of target if it is in nums, or -1 if it is not in nums.
// You must write an algorithm with O(log n) runtime complexity.

// Algorithm
// As the array is rotated by some 1 < k < n, the highest and lowest number will be in the middle.
// We can find the key by changing the conditions of the middle element.


//If mid is lower than lo 


class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int lo, int hi){
        if (lo ==hi) return -1;
        int mid = lo + (hi-lo)/2;
        cout << lo << " : " << mid << " : " << hi << endl; getchar();
        if (target == nums[mid]) return mid;
        else if(target > nums[mid]) return binarySearch(nums, target,mid +1, hi);
        else return binarySearch(nums, target, lo, mid-1);
    }



    int findsmallest(vector<int>& nums, int lo, int hi){
        if (lo==hi) return lo;

        int mid = lo + (hi-lo)/2;

        if( nums[mid] > nums[mid+1]) return mid+1;
        else if (nums[mid] > nums[lo]) return findsmallest(nums, mid+1, hi);
        else return findsmallest(nums, lo, mid);
    }

    int search(vector<int>& nums, int target) {
        int pivInd, res1, res2;
        pivInd = findsmallest(nums, 0, nums.size()-1); 
        cout << "smallest element resides in index: " << pivInd << endl;

        res1 =  binarySearch(nums, target, pivInd, nums.size()-1);
        res2 =  binarySearch(nums, target, 0, pivInd-1);
        return res1 > res2 ? res1: res2;
    }
};


int main(){
    //vector<int> vec {4,5,6,7,8,10,-4,-3,-2,-1,0,1,2,3};
    vector<int> vec {4,5,6,7,0,1,2};
    vector<int> v3 {0,1,2,3,4,5,6,7};
    vector<int> v2 {1,3};

    Solution s;

    cout << s.search(v3, 5) << endl;   


    return 0;
}