#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int res=0;

        vector<vector<bool>> bin(nums.size(), vector<bool> (32, false));
        for(int iter=0; iter<nums.size(); iter++){
            for(int pos=0; pos< 32; pos++){
                int mask = 1<<pos;
                if(mask & nums[iter]) bin[iter][pos] = true;
            }
        }

        for(int pos=0; pos<32; pos++){
            int counter=0;
            for(int iter=0;iter<nums.size(); iter++){
                if(bin[iter][pos]) counter++;
            }
            if(counter >=k){
                res += 1<<pos;
            }
        }

        return res;
    }
};



