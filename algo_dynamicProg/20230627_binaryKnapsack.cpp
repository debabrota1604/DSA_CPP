#include<bits/stdc++.h>
using namespace std;

// Given a knapsack weight capacity of K and an array of weights W with corresponding values V, compute the maximum value of knapsack possible with maximum weight upto K.

class Knapsack{
    int maxWeight;
    vector<int> weights, values;
    unordered_map<int, unordered_map<int,int>> memo;

    public:
    Knapsack(int capacity, vector<int> weights, vector<int> values){
        this->maxWeight = capacity;
        this->weights = weights;
        this->values = values;
    }

    int knapsack(vector<int>& weight, vector<int>& value, int index, int cap){
        if(index <0) return 0;
        if(weight[index] > cap) return knapsack(weight, value, index -1, cap); 
        else return max(knapsack(weight, value, index -1, cap), // Exclude weight[i]
                    knapsack(weight, value, index -1, cap-weight[index]) + value[index]); // include weight[i]
    }

    int knapsack_memoization(vector<int>& weight, vector<int>& value, int index, int cap, vector<vector<int, int>>& dp){
        if(index <0) return 0;
        if(dp[index][cap] != -1) return dp[index][cap];

        dp[index][cap] = max(knapsack(weight, value, index -1, cap), // Exclude weight[i]
                    knapsack(weight, value, index -1, cap-weight[index]) + value[index]);

        return dp[index][cap];
    }

    int knapsack_tabulation(vector<int>& weight, vector<int>& value, int items, int cap){
        //step 1: Create DP array
        vector<vector<int>> dp(items, vector<int> (cap +1, 0));

        //step 2: analyse base case
        for(int w = weight[0]; w <= cap; w++){
            if(weight[0] <= cap)
                dp[0][w] = value[0];
            else
                dp[0][w] =0;
        }

        //Step 3: replace recursive calls
        for(int index=1; index<items; index++){
            for(int w=0; w <= cap; w++){
                int incl, excl;
                incl = excl = INT_MIN;
                if(weight[index] <= w)
                    incl = dp[index -1][w - weight[index]] + value[index];
                excl = dp[index -1][w];
                dp[index][w] = max(incl, excl);
            }
        }
        return dp[items][cap];
    }

    int solve_tabulation_spaceOpt(vector<int>& weight, vector<int>& value, int items, int cap){
        vector<int> prev (cap+1, 0);
        vector<int> curr (cap+1, 0);

        //step 2: analyse base case
        for(int w = weight[0]; w <= cap; w++){
            if(weight[0] <= cap)
                prev[w] = value[0];
            else
                prev[w] =0;
        }

        //Step 3: replace recursive calls
        for(int index=1; index<items; index++){
            for(int w=0; w <= cap; w++){
                int incl, excl;
                incl = excl = INT_MIN;
                if(weight[index] <= w)
                    incl = prev[w - weight[index]] + value[index];
                excl = prev[w];
                curr[w] = max(incl, excl);
            }
        }
        return prev[cap];
    }


    int maxValueSelection(int index,int availableCapacity){
        if(index <0) return 0;
        else if(memo.find(index) != memo.end() && memo[index].find(availableCapacity) != memo[index].end()) return memo[index][availableCapacity];
        else{
            // Calculate weight without the present indexed item
            memo[index][availableCapacity] = maxValueSelection(index-1,availableCapacity);

            if(availableCapacity-weights[index] >=0){
                // Update the value if weight considering current index item is greater.
                memo[index][availableCapacity] = max(memo[index][availableCapacity],maxValueSelection(index-1, availableCapacity-weights[index]) + values[index]);
            }

            //cout << index << "," << availableCapacity << ":" << memo[index][availableCapacity] << endl;
            return memo[index][availableCapacity];
        }
    }
};


int main(){
    Knapsack k(10,{2,3,5,10,12},{2,3,5,10,12});
    cout << "Result: " << k.maxValueSelection(4,16) << endl;
}