#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int,int> m;
        for(int it=0; it<nums.size(); it++){
            if (nums[it] %2==0)
                m[nums[it]]++;
        }

        int mx=-1;
        for(auto item:m){
            if (item.second > mx)
                mx = item.second;
        }
        if (mx == -1) return -1;
        for(auto item:m){
            if (item.second == mx) return item.first;
        }
        return -1;
    }
    
};


int main(){
    Solution s;
    vector<int> v {0,1,2,2,4,4,1}, v2 {4,4,4,9,2,2,2,2,4}, v3 {29, 47, 21, 41, 13, 37, 25, 7};

    cout << s.mostFrequentEven(v3) << endl;
}
