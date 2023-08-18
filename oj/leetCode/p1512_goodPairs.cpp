#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPermute(int n, int r){
        int res=1;
        for (auto i=n; i>=(n-r+1); i--){// multiply n*(n-1)*...*(n-r+1)
            res *=i; 
        }
        //cout << "permute " << n << "," << r << ": " << res<< endl;
        return res;
    }
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> ht; int goodPair=0;

        //freqCounter in hash
        for(auto i:nums){
            if(ht.find(i)==ht.end()){ ht[i] = 1; }
            else{ ht[i] += 1;}
        }

        //compute ordered sets
        for(auto i:ht){
            goodPair += findPermute(i.second, 2)/2; 
            //divide by 2 for finding only ordered pairs of (i<j)
        }

        return goodPair;
    }
};

// Problem: Given an array of integers nums, return the number of good pairs.
// A pair (i, j) is called good if nums[i] == nums[j] and i < j.

// Solution:
// 1. make a reverse hash table: hashIndex = nums[i], hashVal = frequency of nums[i]
// 2. for all element in nums, increment hashIndex[nums[i]].
// 3. for all ement in hash[i], count the number of ordered pairs can be constructed 
//     from hash[i], where (i,j) is a pair if i<j.
// 4. return the total number of pairs possible.


int main(){
    Solution s;
    vector<int> nums { 1,1,1,1 };
    cout <<  s.numIdenticalPairs(nums)  << endl;

    return 0;
}