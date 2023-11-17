#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 =0, sum2 = 0, res=0;
        int zero1=0, zero2=0;

        // Step1: Count sum & zero indices
        for(auto num:nums1){
            if(num==0) zero1++;
            else sum1 += num;
        }
        for(auto num:nums2){
            if(num==0) zero2++;
            else sum2 += num;
        }

        // Step2: Conditional computation for res
        if(zero1 >0 && zero2 >0){
            res = max(sum1+zero1, sum2+zero2);
        }
        else if(zero1 >0){
            if(sum2 >= sum1 +zero1) res = sum2;
        }
        else if(zero2 >0){
            if(sum1 >= sum2 +zero2) res = sum1;
        }
        return res==0 ? -1:res;
    }
};

/*
Result:
Wrong answer for hidden testcase
*/