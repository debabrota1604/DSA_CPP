#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        int longestAlternatingSubarray(vector<int> &nums, int threshold)
        {
            int maxLen = 0, tempLen=0;

            for (int i = 0; i < nums.size(); i++)
            {
                if(tempLen>0){
                    if(( (nums[i]+nums[i-1])&1) && nums[i] <= threshold){
                        tempLen++;
                    }
                    else{
                        maxLen = max(maxLen, tempLen);
                        tempLen=0;
                    }
                }
                if (tempLen ==0 && !(nums[i]&1) && nums[i] <= threshold){
                    tempLen++;
                    //cout << i << " flag true\n";
                }
                //cout << "flag: " << tempLen << endl;
            }
            maxLen = max(maxLen, tempLen);
            return maxLen;
        }
};
