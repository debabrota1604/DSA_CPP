#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int gcd(int x,int y){ return y==0 ? x:gcd(y,x%y); }

    bool gcdArray(vector<int>& nums, int lo, int hi, int k){
        if(lo==hi) return nums[lo]==k ? true:false;

        int res=nums[lo];
        for(int it=lo+1;it<=hi; it++){
            res = gcd(res, nums[it]);
            if(res!=k) return false;
        }
        return res==k ? true:false;
    }

    int subarrayGCD(vector<int>& nums, int k) {
        int count=0;
        for(int i=0; i<nums.size();i++)
            for(int j=i; j<nums.size(); j++)
                if(gcdArray(nums, i, j, k)) count++;
        
        return count;
    }
};

int main(){
    vector<int> nums; int k;
    nums = {4}, k=7;
    nums = {9,3,1,2,6,3}, k=3;

    Solution s;
    cout << s.subarrayGCD(nums, k) << endl;



}