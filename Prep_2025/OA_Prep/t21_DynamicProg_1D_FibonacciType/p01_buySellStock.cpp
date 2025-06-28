#include <bits/stdc++.h>
using namespace std;

/*
Given an array of stock prices where prices[i] is the price of a given stock on the ith day,
find the maximum profit you can achieve by buying on one day and selling on another day later.

You may engage in multiple transactions (i.e., you must sell the stock before you buy again).
*/
int maxProfit(int index, int buyIndex, int profit, vector<int>& prices) {
    if (index >= prices.size()) { // Base case: no more days to process
        if(buyIndex == -1)  
            return profit; // Last day: Cannot sell if buy today
        else{ // Already bought stock, check if we can sell
            int tempProfit = prices[index] - prices[buyIndex];
            return (tempProfit > 0) ? profit + tempProfit : profit; 
        }
    }
    if(buyIndex == -1) { // If we haven't bought stock yet
        int buyProfit = maxProfit(index + 1, index, profit, prices); // Buy today
        int skipBuyProfit = maxProfit(index + 1, buyIndex, profit, prices); // Skip buying today
        return max(buyProfit, skipBuyProfit);
    } 
    else { // If we have already bought stock
        int tempProfit = prices[index] - prices[buyIndex];
        int sellProfit = maxProfit(index + 1, -1, profit + tempProfit, prices); // Sell today
        int holdProfit = maxProfit(index + 1, buyIndex, profit, prices); // Hold the stock
        return max(sellProfit, holdProfit);
    }
}




int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Max Profit: " << maxProfit(0, -1, 0, prices) << endl;

    return 0;
}