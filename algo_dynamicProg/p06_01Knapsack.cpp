#include<bits/stdc++.h>
using namespace std;

// Recursive call:
int recurse(const vector<int>& profit, const vector<int>& weight, int index, int capacity){
    if(index<0 || capacity<=0 ) return 0; //base case

    int res=INT_MIN; //cout << "Call: " << index << ":" << capacity << endl;
    res = max(res, recurse(profit, weight, index-1, capacity)); //if we don't select element w[i]

    if(weight[index] <= capacity) // Select the element if there is space available
        res = max(res, profit[index] + recurse(profit, weight, index-1, capacity-weight[index]));

    return res;
}

void dp01_recursion(){ //recursion caller function
    vector<int> profit {60,100,120}, weight {10,20,30}; 
    int MaxWeight=40;
    cout << recurse(profit, weight, profit.size()-1, MaxWeight) << endl;
}

// Memoization call:
int memoize(const vector<int>& profit, const vector<int>& weight, vector<vector<int>>& memo, int index, int capacity){
    if(index<0 || capacity<=0 ) return 0; //base case
    if(memo[index][capacity] != -1) return memo[index][capacity];

    int res=INT_MIN;
    res = max(res, memoize(profit, weight, memo, index-1, capacity)); //if we don't select element w[i]

    if(weight[index] <= capacity) // Select the element if there is space available
        res = max(res, profit[index] + memoize(profit, weight, memo, index-1, capacity-weight[index]));

    memo[index][capacity] = res;
    return res;
}

void dp02_memoization(){ //memoization caller function
    vector<int> profit {60,100,120}, weight {10,20,30}; 
    int MaxWeight=40;

    // Matrix size is of [profile.size()+1][maxWeight+1].
    vector<vector<int>> memo (profit.size()+1, vector<int> (MaxWeight+1,-1));
    
    cout << memoize(profit, weight, memo, profit.size()-1, MaxWeight) << endl;
}

// top-down call:
int topdown()


int main(){
    //dp01_recursion();
    dp02_memoization();
    
    return 0;
}