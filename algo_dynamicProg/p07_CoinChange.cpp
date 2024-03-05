#include<bits/stdc++.h>
using namespace std;

static int run=0;

int sum; 
map<int,int> dp;
map<pair<int,int>,int> options_dp;

int getMin(int x, int y){ return x<y ? x:y; }
int getMax(int x, int y){ return x>y ? x:y; }

//find the minimum number of coins to make the sum
int minChange(vector<int>& coins, int remSum){
    //cout << "Call: minchange(" <<remSum << ")\n";
    if(remSum <=0) return 0;
    if(dp.find(remSum) !=dp.end()) return dp[remSum];

    int res=INT_MAX;
    for(auto iter:coins) 
        res = min(res, minChange(coins, remSum - iter) +1);

    //cout << "Result for minCOinRequird(" << remSum << "): " << res<< endl;
    dp[remSum] =res; 
    return res;
}

//find the minimum number of coins to make the sum
int minChange_bottomUp(vector<int>& coins, int remSum){
    vector<int> dp(remSum +1, INT_MAX);
    dp[0] =0;

    for(int iter=1; iter<=remSum; iter++){
        for(int i2=0; i2<coins.size(); i2++){
            if(iter >= coins[i2] && dp[iter-coins[i2]] !=INT_MAX){
                dp[iter] = min(dp[iter], dp[iter - coins[i2]] +1);
            }
        }
    }
    return dp.back();
}

int allOptions(vector<int>& coins, int remSum, int lastCoinIndex){
    //cout << "Call " << ++run << ": allOptions(" << remSum << "," << lastCoinIndex << ")\n";
    if(remSum==0) return 1;
    if(remSum <0) return 0;

    int res=0; 
    pair<int, int> p =make_pair(remSum, lastCoinIndex);
    if(options_dp.find(p) != options_dp.end()) 
        return options_dp[p];
    
    for(int i=lastCoinIndex; i>=0; i--) if(remSum >= coins[i]) 
        res += allOptions(coins, remSum - coins[i], i);

    //cout << "Result for Options(" << remSum << "," << " coins at max " << coins[lastCoinIndex] << "): "<< res << endl; 
    options_dp[p] = res; 
    return res;
}

int main(){
    //coins = {1,2,3}, sum=4;
    vector<int> coins {2,5,3,6};
    int sum=10;
    sort(coins.begin(), coins.end());
    //coins = {1,2,3}, sum=6;
    cout << minChange(coins, sum) << " is the minimum number of coins needed..." << endl;
    cout << minChange_bottomUp(coins, sum) << " is the minimum number of coins needed..." << endl;
    cout << allOptions(coins, sum, coins.size()-1) << " is the maximum possibilities to serve this sum..." << endl;

    return 0;
}