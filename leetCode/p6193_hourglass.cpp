#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int hr = grid.size()-3, hc = grid[0].size()-3, sum=INT_MIN, maxSum=INT_MIN;
        cout << hr << " " << hc << endl;
        for(int i1=0; i1<=hr; i1++){
            for(int i2=0; i2<=hc; i2++){
                sum = grid[i1][i2] + grid[i1][i2+1] + grid[i1][i2+2] + grid[i1+1][i2+1] + grid[i1+2][i2] + grid[i1+2][i2+1] + grid[i1+2][i2+2];
                if(sum > maxSum) maxSum = sum;
            }
        }
        return maxSum;
    }
};


int main(){
    Solution s;
    vector<vector<int>> v {{1,2,3},{4,5,6},{7,8,9}};
    cout << s.maxSum(v) << endl;


    return 0;
}