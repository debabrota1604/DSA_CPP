#include<bits/stdc++.h>
using namespace std;

int minCostStairClimbing_topDown(int stairLen){
    if(stairLen <=1) return stairLen;
    return min( minCostStairClimbing_topDown(stairLen -1) +1, minCostStairClimbing_topDown(stairLen-2) +1);
}

int minCostStairClimbing_bottomUp(int stairLen){
    int res=0;
    vector<int> dp (stairLen+1, 0);
    dp[1] = 1;
    for(int iter=2; iter <= stairLen; iter++){
        dp[iter] = min(dp[iter-1] +1, dp[iter-2] +1);
    }
    return dp[stairLen];
}

int minCostStairClimbing_bottomUp_spaceOpt(int stairLen){
    if(stairLen <=1) return 1;
    int s1,s2,s3;
    s1=0, s2=1;
    for(int iter=2; iter<=stairLen; iter++){
        s3 = min(s1, s2) +1;
        s1 = s2;
        s2 = s3;
    }
    return s3;
}


int main(){
    int stairLen = 5;
    cout << "Min cost to climb stair of step " <<  stairLen << " : " << minCostStairClimbing_topDown(stairLen) << endl;
    cout << "Min cost to climb stair of step " <<  stairLen << " : " << minCostStairClimbing_bottomUp(stairLen) << endl;
    cout << "Min cost to climb stair of step " <<  stairLen << " : " << minCostStairClimbing_bottomUp_spaceOpt(stairLen) << endl;


    return 0;
}