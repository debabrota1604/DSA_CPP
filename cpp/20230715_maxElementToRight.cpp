#include<bits/stdc++.h>
using namespace std;

// Given an array of random unsorted integers return the maximum difference j-i where i<j and A[i]<A[j].

int solve(vector<int> inp){
    int mx = inp[0], mn = inp[0], diff = -1, iter;
    for(int iter=1;iter<inp.size(); iter++){
        if(inp[iter] > mx){
            mx = inp[iter];
            diff < mx-mn ? diff = mx-mn:1;
        } 
        else if(inp[iter] < mn){
            mn = inp[iter];
            mx = inp[iter];
        }
    }
    return diff;
}


int main(){
    vector<int> v {2, 3, 10, 6, 4, 8, 1};// answer 8: The maximum difference is between 10 and 2.
    vector<int> v2 {7, 9, 5, 6, 3, 2}; // 2: The maximum difference is between 9 and 7.

    cout << solve(v) << endl;
    cout << solve(v2) << endl;
}