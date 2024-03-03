#include<bits/stdc++.h>
using namespace std;

int maxPossibleStairClimbing_topDown(int stairLen){
    if(stairLen <=1) return stairLen;
    return maxPossibleStairClimbing_topDown(stairLen -1) +  maxPossibleStairClimbing_topDown(stairLen-2) +1;
}

int maxPossibleStairClimbing_bottomUp(int stairLen){
    int res=0;
    vector<int> dp (stairLen+1, 0);
    dp[1] = 1;
    for(int iter=2; iter <= stairLen; iter++){
        dp[iter] = dp[iter-1] + dp[iter-2] +1;
    }
    return dp[stairLen];
}

int maxPossibleStairClimbing_bottomUp_spaceOpt(int stairLen){
    if(stairLen <=1) return stairLen;
    int s1,s2,s3;
    s1 = 0;
    s2 = 1;
    for(int iter=2; iter<=stairLen; iter++){
        s3 = s1 + s2 +1;
        s1 = s2;
        s2 = s3;
    }
    return s3;
}




int main(){
    int stairLen = 5;
    cout << "Mas possibilities to climb stair of step " <<  stairLen << " : " << maxPossibleStairClimbing_topDown(stairLen) << endl;
    cout << "Min cost to climb stair of step " <<  stairLen << " : " << maxPossibleStairClimbing_bottomUp(stairLen) << endl;
    cout << "Min cost to climb stair of step " <<  stairLen << " : " << maxPossibleStairClimbing_bottomUp_spaceOpt(stairLen) << endl;


    return 0;
}