#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i=0,j=nums.size()-1; set<float> s;
        while(i<=j){cout << (nums[i]+nums[j])/2 << endl; s.insert((float)(nums[i]+nums[j])/2); i++;j--;}
        return s.size();
        
    }
};

int main(){
    Solution s; vector<int> v {9,5,7,8,7,9,8,2,0,7};
    cout << s.distinctAverages(v) << endl;

}