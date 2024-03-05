#include<bits/stdc++.h>
using namespace std;

//Given an input array and a target sum, determine in how many ways the target sum can be achieved.
// Once element can be selected multiple times.

class CombinatorialSum{
    vector<int> array;
    unordered_map<int,int> memo;

    public:
    CombinatorialSum(vector<int> inp){
        this->array = inp;
    }
    int countCombinatorialSum(int remainingSum){
        if(memo.find(remainingSum) != memo.end()) return memo[remainingSum];
        int counter=0;
        for(int iter=0; iter<array.size(); iter++){
            if(remainingSum -array[iter] ==0) counter++;
            else if(remainingSum - array[iter] > 0) counter += countCombinatorialSum(remainingSum - array[iter]);
        }
        return (memo[remainingSum] = counter);
    }
};

int combSum(vector<int>& num, int target){
    if(target <0) return 0;
    if(target ==0) return 1;

    int counter=0;
    for(int iter=0; iter<num.size(); iter++){
        counter += combSum(num, target - num[iter]);
    }
    return  counter;
}
int combSum_memoization(vector<int>& num, vector<int>& dp, int target){
    if(target <0) return 0;
    if(target ==0) return 1;

    if(dp[target] != -1) return dp[target];

    int counter=0;
    for(int iter=0; iter<num.size(); iter++){
        counter += combSum_memoization(num, target - num[iter]);
    }
    dp[target] = counter;
    return  counter;
}

int combSum_Tabulation(vector<int>& num, int target){
    vector<int> dp (target+1, -1);
    dp[0] =1;
    for(int iter=1; iter<=target; iter++){ // loop for all target possibilities
        for(int j=0; j<num.size(); j++){    // loop for all num elements
            if(iter - num[j] >=0)
                dp[iter] += dp[iter - num[j]];
        }
    }
    return dp[target];
}

class CombinatorialSumIterative{
    vector<int> array;

    public:
    CombinatorialSumIterative(vector<int> inp){ this->array = inp; }
    int coutIterative(){
        
    }
}


int main(){
    CombinatorialSum cs({1,2,5});
    cout << "Total ways to get the target: " << cs.countCombinatorialSum(5) << endl;

    return 0;

}