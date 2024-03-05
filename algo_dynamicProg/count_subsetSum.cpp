#include<bits/stdc++.h>
using namespace std;

#define PR pair<int,int> 
#define MP make_pair 
unordered_map<PR, int> dp;

int countSubsetSum(vector<int> nums,int sum, int lo){
    if(lo==nums.size())
        if(sum==0) return 1; //add 1 to the number of solutions found
        else return 0;

    PR state = MP(lo,sum);
    if(dp.find(state) !=dp.end()) return dp[state];
    else dp[state] = countSubsetSum(nums, sum, lo+1) + countSubsetSum(nums, sum-nums[lo], lo+1);

    return dp[state];
}




int main(){
    vector<int> ip {3, 3, 3, 3}, ip2 {5,5,10};
    cout << countSubsetSum(ip,6,0) << endl; dp.clear();
    cout << countSubsetSum(ip2,10,0) << endl;

}