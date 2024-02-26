#include<bits/stdc++.h>
using namespace std;


class Solution {
    unordered_map<int, unordered_map<int, int>> gcdMap;
    int gcd(int a, int b){
        if(a ==0) return b;
        return gcd(b%a, a);
    }
public:
    bool pairCheck(vector<int>& nums, int ind1, int ind2){
        return false;
    }
    bool canTraverseAllPairs(vector<int>& nums) {
        for(int iter=0; iter<nums.size(); iter++){
            for(int i2=iter +1; i2<nums.size(); i2++){
                gcdMap[iter][i2] = gcd(nums[iter], nums[i2]);
            }
        }
        for(auto iter:gcdMap){
            for(auto iter2:iter.second){
                cout << iter.first << " " << iter2.first << " " << iter2.second << endl;
            }
        }
        for(int iter=0; iter<nums.size(); iter++){
            for(int i2=iter +1; i2<nums.size(); i2++){
                if(!pairCheck(nums, iter, i2)) return false;
            }
        }
        return true;
    }
};


int main(){
    vector<int> v {2,3,6};
    Solution s;
    cout << s.canTraverseAllPairs(v) << endl;


    return 0;
}