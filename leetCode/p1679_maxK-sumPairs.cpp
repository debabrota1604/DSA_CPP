#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maxOperations(vector<int>& nums, int k) {
            sort(nums.begin(),nums.end());
            int fro = 0, rev=nums.size()-1, res=0;
            while(fro < rev){
                if (nums[fro] + nums[rev] > k) rev--;
                else if(nums[fro] + nums[rev] <k ) fro++;
                else {fro++; rev--; res++;}
            }
            return res;
        }
};
