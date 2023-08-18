#include<bits/stdc++.h>
using namespace std;

vector<int> rodLen = {1,2,3,4,5,6,7,8}, profit = {1, 5, 8, 9, 10, 17, 17, 20};
unordered_map<int, int> dp;

// void printMemory(){
//     //for(int i=0; i<dp.size();i++) cout << "DP[" << i << "]: " << dp[i] << endl;
//     for(auto i:dp) cout << "DP[" << i.first << "]: " << i.second << endl;
// }

int maxProfitTopDownRecursion(int n){
    if (n==0) return 0;
    int tempProfit, recIndex, maxProfit=INT_MIN;
    for(int it=0; it<rodLen.size(); it++){
        tempProfit = profit[it]; recIndex = n-rodLen[it]; 
        if(recIndex <0) continue;

        if(dp.find(recIndex) !=dp.end()) tempProfit+= dp[recIndex];
        else tempProfit +=maxProfitTopDownRecursion(recIndex);

        if(maxProfit< tempProfit){ maxProfit = tempProfit;}
        cout << "N: " << n << " it: " << it << " recIndex: " << recIndex << " new tp: " << tempProfit << " maxProfit: " << maxProfit << endl;
    }
    dp[n] = maxProfit; cout << "Memory Update: DP[" << n << "]: " << dp[n] << endl;  return maxProfit;
}


int main(){

    cout << "rodLen:"; for(int i=0; i<rodLen.size(); i++){ cout << rodLen[i] << "\t"; } cout << endl;
    cout << "Price :"; for(int i=0; i<profit.size(); i++){ cout << profit[i] << "\t"; } cout << endl;

    int len; cout << "Enter Rod rodLen: ";  cin >>  len;
    cout << "Maximum profit using memoization for rod rodLen " << len << " is: " << maxProfitTopDownRecursion(len) << endl;

    return 0;
}