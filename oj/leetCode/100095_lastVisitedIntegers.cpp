#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) {
        vector<int> res;
        vector<int> nums;
        for(int iter=0; iter<words.size(); iter++){
            if(words[iter][0] != 'p'){
                nums.emplace_back(stoi(words[iter]));
            }
            else{
                nums.emplace_back(-1);
            }
        }
        
        for(int iter=0; iter<nums.size(); iter++){
            if(words[iter][0] == 'p'){
                int prev = iter-1, count=1;
                while(prev >=0 && count >0){
                    if(words[iter][0] == 'p') count++;
                    else count--;
                    prev--;
                }
                if(nums[prev] <0) res.emplace_back(-1);
                else res.emplace_back(nums[prev]);
            }
        }
        return res;
    }
};