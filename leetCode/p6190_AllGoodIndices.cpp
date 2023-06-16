#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool IsNonIncr(vector<int>& nums, int lo, int hi){
        bool res=true;
        for(int i=lo; i<hi-1; i++){
            if(nums[lo] > nums[lo+1]) res *= 0;
        }
        return res;
    }
    bool IsNonDecr(vector<int>& nums, int lo, int hi){
        bool res=true;
        for(int i=lo; i<hi-1; i++){
            if(nums[lo] < nums[lo+1]) res *= 0;
        }
        return res;
    }
    vector<int> goodIndices(vector<int>& nums, int k) {
        vector<int> res; bool lf=true, rf=true; int l,r;
        for(int i=k; i<nums.size()-k;i++)
            if (IsNonIncr(nums,i-k,i-1) && IsNonDecr(nums, i+1, i+k) ) res.emplace_back(i);
        return res;
    }
};


int main(){



    return 0;

}