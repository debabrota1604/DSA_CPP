#include<bits/stdc++.h>
using namespace std;

vector<int> nums; 
map<pair<int,int>,int> dp;

int lisTopDown(pair<int,int> p){
    if(p.first<0) return 0;
    if(dp.find(p) !=dp.end()) return dp[p];

    int tempRes1=0, tempRes2=0,res;
    if(nums[p.first]>nums[p.first-1]) tempRes1 = lisTopDown(make_pair((p.first)-1, nums[(p.first)-1])) +1;
    tempRes2 = lisTopDown(make_pair((p.first)-1,p.second)); // not considering num[index] in LIS

    res =  tempRes1>tempRes2 ? tempRes1:tempRes2; dp[p] = res;
    cout << "State: [" << p.first << "," << p.second << "]: " << res << endl;
    return res;
}

int lisBottomUp(pair<int,int> p){
    if(nums.size()<=1) return nums.size();

    for(int iter=1;iter<nums.size();iter++){

    }
}


int main(){
    nums = {10,22,9,33,21,50,41,60,80}; 
    pair<int,int> p = make_pair(nums.size()-1, *nums.end());
    //cout << lisTopDown(p) << " is the final result" << endl;
    cout << lisBottomUp(p) << " is the final result" << endl;

    return 0;
}