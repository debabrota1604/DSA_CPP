#include<bits/stdc++.h>
using namespace std;

int maxVal(const vector<int>& profit, const vector<int>& weight, int index, int availSpace){
    int res=INT_MIN; //cout << "Call: " << index << ":" << availSpace << endl;
    if(index<0 || availSpace<=0 ) return 0; //base case

    res = max(res, maxVal(profit, weight, index-1, availSpace)); //if we don't select element w[i]

    if(weight[index] <= availSpace) // Select the element if there is space available
        res = max(res, profit[index] + maxVal(profit, weight, index-1, availSpace-weight[index]));

    return res;
}

int main(){
    vector<int> profit {60,100,120}, weight {10,20,30}; 
    int MaxWeight=40;
    cout << maxVal(profit, weight, profit.size()-1, MaxWeight) << endl;
    return 0;
}