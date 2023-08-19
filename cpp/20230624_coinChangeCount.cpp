#include<bits/stdc++.h>
using namespace std;


class CoinChange{
    vector<int> coins;
    unordered_map<int,long long unsigned> memo;
    public:
    CoinChange(vector<int> inpCoin){
        this->coins=inpCoin;
    }

    void memorise(int sum, int count){
        memo[sum] = count;
    }

    long long unsigned recall(int sum){
        if(memo.find(sum) != memo.end()){
            return memo[sum];
        }
        return 0;
    }

    long long unsigned computeWays(int sum){
        if(sum ==0) return 1;

        long long unsigned res=recall(sum);
        if(res != 0) return res;

        for(auto iter=0; iter<coins.size(); iter++){
            if(sum - coins[iter] >=0 ){
                res += computeWays(sum - coins[iter]);
            }
        }
        //cout << "computeWays[" << sum << "]: " << res << endl;
        memorise(sum, res);
        return res;
    }
};

class CoinChangeIterativeDP{
    vector<int> coins;
    public:
    CoinChangeIterativeDP(vector<int> inp){ this->coins = inp;}
    
    long long unsigned computeWays(int sum){
        vector<int> memo (sum+1,0);

        memo[0] = 1;

        for(int iter=1; iter<=sum; iter++){
            unsigned long long res=0;
            for(int iter2=0; iter2<coins.size(); iter2++){
                if(iter-coins[iter2]>=0){
                    res += memo[iter-coins[iter2]];
                }
            }
            memo[iter] = res; 
        }
        return memo[sum];

    }
};


int main(){
    CoinChange cc({1,3,5});
    int sum = 6;
    cout << "Number of ways to sum " << sum << " via recursion is: " << cc.computeWays(sum) << endl;

    CoinChangeIterativeDP cci({1,3,5});
    cout << "Number of ways to sum " << sum << " is: " << cci.computeWays(sum) << endl;


    return 0;
}