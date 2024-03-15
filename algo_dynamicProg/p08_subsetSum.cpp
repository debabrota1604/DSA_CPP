#include<bits/stdc++.h>
using namespace std;

/*
Given an array of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum. 

Example 1:
    Input:
    N = 6
    arr[] = {3, 34, 4, 12, 5, 2}
    sum = 9
    Output: 1 
    Explanation: Here there exists a subset with
    sum = 9, 4+3+2 = 9.

Example 2:
    Input:
    N = 6
    arr[] = {3, 34, 4, 12, 5, 2}
    sum = 30
    Output: 0 
    Explanation: There is no subset with sum 30.
*/

bool solve_recurrence(const vector<int>& nums, int target, int index){
    if(index <0 && target >0) return 0;
    if(target == 0) return 1;

    bool res = solve_recurrence(nums, target, index -1);
    if(nums[index] <= target) res = res || solve_recurrence(nums, target - nums[index], index -1);

    /*
    dp[target, index] = solve(nums, target, index-1);
    if(nums[index] <= target) 
        dp[target, index] ||= solve(nums, target - nums[index], index-1);
    */
    
    return res;
}

void recurrence_caller(){
    vector<int> inp {3, 34, 4, 12, 5, 2};
    int target = 9;
    cout << "Recurrence result: " << solve_recurrence(inp, target, inp.size()-1) << endl;
}

bool solve_iterative(const vector<int>& nums, int target){
//Step1: initialization
    // DP array is of size [target+1, nums.size()+1]
    vector<vector<bool>> memo (nums.size()+1, vector<bool> (target+1, false));
    
    // If target is zero, then solution is not there: pick any item will increase target
    for(int iter=0; iter<=target; iter++) memo[0][iter] = false;

    // If target is zero, but items are non-zero, then solution is present: pick no items
    for(int iter=0; iter<=nums.size(); iter++) memo[iter][0] = true;

    memo[0][0] = true; // when target is zero, items are zero, solution is present

// Step2: Iteration
    for(int index =1; index <=nums.size(); index++){
        for(int itarget =1; itarget <=target; itarget++){
            memo[index][itarget] = memo[index-1][itarget];
            if(nums[index] <= itarget)
                memo[index][itarget] = memo[index][itarget] || memo[index -1][itarget - nums[index]];
        }
    }
    return memo[nums.size()][target];
}

bool solve_iterative_spaceOpt(const vector<int>& nums, int target){
    /*
    Idea is to use two 1-D arrays instead of nums.size() depth, as our recursions depend on the last index only
    */

    // Declare the memory
    vector<bool> prev(target+1, false), curr(target+1, false);
    
    // Initialize the memory
    prev[0] = true; // when target is zero, items are zero, solution is present

    // Iterate over all indices to calculate the result
    for(int index =1; index<=nums.size(); index++){
        for(int itgt =1; itgt <=target; itgt++){
            curr[itgt] = prev[itgt];
            if(nums[index] <= itgt) curr[itgt] = (prev[itgt] || prev[itgt - nums[index]]);
        }
        prev = curr; //save the state
    }
    return curr[target];
}

void iterative_caller(){
    vector<int> inp {3, 34, 4, 12, 5, 2};
    int target = 9;
    cout << "Top-down result: " << solve_iterative(inp, target) << endl;

    //not working correctly
    cout << "Top-down space_opt result: " << solve_iterative_spaceOpt(inp, target) << endl;

}


int main(){
    //recurrence_caller();
    iterative_caller();
    
}