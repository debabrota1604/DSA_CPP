#include<bits/stdc++.h>
using namespace std;

// The aim is to minimize/maximize the number of coins for a given amount

class CoinChange{
    vector<int> coins;
    public:
    CoinChange(vector<int> inp) {this->coins = inp;}

    unsigned long long findMinCoins(int sum){
        if(sum==0) return 0;
        for(int iter=0; iter<coins.size(); iter++){
            if(coins[iter] == sum) return 1;
        }

        int res=INT_MAX,tempRes;
        for(int iter=0; iter<coins.size(); iter++){
            if(sum-coins[iter]>0){
                tempRes = findMinCoins(sum - coins[iter]) +1;
                res = res-tempRes>0 ? tempRes:res;
            }
        }
        cout << sum << ":" << res << endl;
        return res;
    }
};

class CoinChangeIterativeDP{
    vector<int> coins;
    public:
    CoinChangeIterativeDP(vector<int> inp){this->coins=inp;}

    unsigned long long findMinCoins(int sum){
        unsigned long long memo[sum+1]; // memo[sum+1] = INT_MAX doesn't work for c-style arrays
        for(int iter=0; iter<sum+1; iter++){ memo[iter] = INT_MAX;} //need this loop as memo is a c-style array.

        //Base Case: memo[0]=0;
        memo[0]=0;

        for(int iter=1; iter<=sum; iter++){
            unsigned long long tempRes = INT_MAX;
            for(int iter2=0; iter2<coins.size(); iter2++){
                if(iter - coins[iter2] >=0){
                    tempRes=(1 + memo[iter - coins[iter2]]);
                    tempRes < memo[iter] ? memo[iter] = tempRes:1;
                }
            }
        }
        return memo[sum];
    }
};



int main(){
    CoinChangeIterativeDP cc({9,6,5,1}); 
    int sum = 15;

    cout << "Minimum number of coins to get sum " << sum << " is: " << cc.findMinCoins(sum) << endl;


    return 0;
}