#include<bits/stdc++.h>
using namespace std;

vector<int> weight, profit; int MaxWeight;

int getMax(int x, int y){ return x>y ? x:y; }

int maxVal(int index, int availSpace){
    int res=INT_MIN; //cout << "Call: " << index << ":" << availSpace << endl;
    if(index<0 || availSpace<=0 ) return 0; //base case

    if(weight[index] <= availSpace){
    res = getMax(res, profit[index] + maxVal(index-1, availSpace-weight[index]));}
    res = getMax(res, maxVal(index-1, availSpace)); //if we don't select the w[i] element

    return res;
}

int main(){
    profit= {60,100,120}, weight= {10,20,30}; MaxWeight=40;
    cout << maxVal(profit.size()-1, MaxWeight) << endl;
    return 0;
}