//This function computes the maximum number of elements resulting in the sum provided as target
// the elements might not be contiguous in the array

#include<bits/stdc++.h>
using namespace std;
unordered_map<int,unordered_map<int,int>> memo;


int findKey(int k1, int k2){
    if(memo.find(k1) !=memo.end()){
        if(memo[k1].find(k2) !=memo[k1].end()){
            return memo[k1][k2];
        }
    }
    return -1;
}


int subsetSum(vector<int>& inp, int setSize, int target){
    int history = findKey(setSize, target);
    if(history != -1){
        //cout << "Returning from history: " << setSize << "," << target << ": " << history << endl;
        return history;
    }

    if(setSize <0){
        if(target ==0) return true;
        else return false;
    }
    if(target-inp[setSize-1] < 0){
        memo[setSize][target] = subsetSum(inp, setSize-1, target);
    }
    else{
        memo[setSize][target] = max(subsetSum(inp, setSize-1, target-inp[setSize-1]), subsetSum(inp, setSize-1, target));
    }
    return memo[setSize][target];
}

// Working code
int solve(vector<int>& inp, int target, vector<int>& tempSet, int lastIndex){
    if(target == 0 ) return tempSet.size();
    if(lastIndex ==0 && target != 0 ) return 0;
    
    int op1, op2 = INT_MIN;
    op1 = solve(inp, target, tempSet, lastIndex-1); //not considering last element in the selected set
    if(inp[lastIndex] <= target){
        tempSet.emplace_back(inp[lastIndex]);
        op2 = solve(inp, target - inp[lastIndex], tempSet, lastIndex-1);
        tempSet.pop_back();
    }

    return max(op1, op2);    
}


int main(){
    vector<int> inp {3, 34, 4, 12, 5, 2};
    int target = 9;
    vector<int> temp;
    cout << solve(inp, target, temp, inp.size()-1) << endl;

    cout << "The maximum number of elements summing to " << target << " is " << subsetSum(inp, inp.size(), target) << endl;


    cout << "Map size: " << memo.size() << endl;
    return 0;
}