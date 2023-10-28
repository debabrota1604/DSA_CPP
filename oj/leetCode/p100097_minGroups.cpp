#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    int minGroupsForValidAssignment(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(auto item:nums) freq[item]++;
        vector<int> justFreq;
        for(auto item: freq){
            justFreq.emplace_back(item.second);
        }

        sort(justFreq.begin(), justFreq.end());

        int res = justFreq.size(), lowSize=0;
        for(int iter=0; iter<justFreq.size(); iter++){
            if(iter ==0) lowSize = justFreq[iter];
            else{
                if(justFreq[iter] == lowSize || justFreq[iter] == lowSize+1) continue;

                int extraGroups1 = INT_MAX, extraGroups2 = INT_MAX;
                int remainder1 = justFreq[iter] % lowSize;
                if(remainder1 == 0){
                    extraGroups1 = justFreq[iter]/ lowSize -1;
                }

                int remainder2 = justFreq[iter] % (lowSize+1);
                if(remainder2 ==0){
                    extraGroups2 = justFreq[iter] / (lowSize+1);
                }
                else if(remainder2 == lowSize){
                    extraGroups2 = min(extraGroups2, justFreq[iter] / (lowSize+1));
                }


                if(extraGroups1 <INT_MAX){
                    res += extraGroups1;
                }
                else if(extraGroups2 < INT_MAX){
                    res += extraGroups2;
                }
            }
        }
        return res;
    }
};