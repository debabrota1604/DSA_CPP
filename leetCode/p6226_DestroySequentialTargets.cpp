#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        sort(nums.begin(), nums.end());
        vector<int> destroy (nums.size(), 0); int count=0,maxInd=0;
        for(int it2=0; it2<nums.size(); it2++){
            for(int it=0; it<nums.size(); it++){
                float f = nums[it2] - nums[it]; f/=space;
                if(f -int(f) ==0 && f>=0) count++;
            }
            destroy.emplace_back(count);
        }

        for(int i=0; i<nums.size(); i++){
            if(destroy[i] > destroy[maxInd]) maxInd=i;
        }
        return nums[maxInd];
    }
};




int main(){
    Solution s;
    vector<int> nums; int space;
    nums = {3,7,8,1,1,5}; space = 2;
    cout << s.destroyTargets(nums, space) << endl;
    nums = {2,3,5,2,4,6}; space = 3;
    cout << s.destroyTargets(nums, space) << endl;
    nums = {1,5,3,2,2}; space = 1000;
    cout << s.destroyTargets(nums, space) << endl;

    return 0;
}