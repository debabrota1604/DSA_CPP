//This function computes the maximum number of elements resulting in the sum provided as target

#include<bits/stdc++.h>
using namespace std;
vector<int> inp {2,3,5,4,1,1,3};
unordered_map<int,unordered_map<int,int>> memo;


int findKey(int k1, int k2){
    if(memo.find(k1) !=memo.end()){
        if(memo[k1].find(k2) !=memo[k1].end()){
            return memo[k1][k2];
        }
    }
    return -1;
}


int subsetSum(int setSize, int target){
    int history = findKey(setSize, target);
    if(history != -1){
        cout << "Returning from history: " << setSize << "," << target << ": " << history << endl;
        return history;
    }

    if(setSize <0){
        if(target ==0) return true;
        else return false;
    }
    if(target-inp[setSize-1] < 0){
        memo[setSize][target] = subsetSum(setSize-1, target);
    }
    else{
        memo[setSize][target] = max(subsetSum(setSize-1, target-inp[setSize-1]), subsetSum(setSize-1, target));
    }
    return memo[setSize][target];
}


int main(){

    int target = 10;

    cout << "The maximum number of elements summing to " << target << " is " << subsetSum(inp.size(), target) << endl;


    cout << "Map size: " << memo.size() << endl;
    return 0;
}