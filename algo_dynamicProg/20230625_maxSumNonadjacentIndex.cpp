#include<bits/stdc++.h>
using namespace std;

// Determine maximum sum of an array while selecting no adjacent elements

class ElementSum{
    vector<int> elements;
    unordered_map<int,int> memo;
    public:
    ElementSum(vector<int> inp){
        this->elements = inp;
    }
    int findMaxSum(int index){
        if(index<0) return 0;
        else if(index==0 || index==1) return elements[index]; //Base Case
        else if(memo.find(index) != memo.end()) return memo[index];
        else{
            auto res = max(findMaxSum(index-1),findMaxSum(index-2) + elements[index]);
            cout << index << ":" << res << endl;
            memo[index] = res;
            return res;
        } 
    }
    int findMaxSum(){
        return findMaxSum(elements.size()-1);
    }
};

int solve_tabulation(vector<int> nums){
    int sz = nums.size();
    vector<int> dp(sz,0);
    dp[0] = nums[0];
    for(int iter=1; iter<sz; iter++){
        int incl = dp[iter] + nums[iter];
        int excl = dp[iter-1];
        dp[iter] = max(incl, excl);
    }
    return dp[sz-1];
}

int solve_tabulation_spaceOpt(vector<int> nums){
    int sz = nums.size();
    int prev1, prev2;
    prev2 = 0;
    prev1 = nums[0];

    for(int iter=1; iter<sz; iter++){
        int incl = prev2 + nums[iter];
        int excl = prev1;
        int ans = max(incl, excl);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}


class ElementSumIterative{
    vector<int> elem;
    public:
    ElementSumIterative(vector<int> inp){
        this->elem = inp;
    }
    int findMaxSum(){
        int memo[2] = {elem[0],elem[1]};

        for(int iter=2;iter<elem.size();iter++){
            memo[iter&1] = max(memo[(iter-1)&1], memo[(iter-2)&1]+elem[iter]);
            cout << iter << ":" << memo[iter&1] << endl;
        }
        return memo[(elem.size()-1)&1];
    }
};



int main(){
    ElementSum es({5, 5, 10, 100, 10, 105});
    ElementSumIterative esi({5, 5, 10, 100, 10, 105});

    cout << "Solution: " << es.findMaxSum() << endl;
    cout << "Iterative Solution: " << esi.findMaxSum() << endl;
}