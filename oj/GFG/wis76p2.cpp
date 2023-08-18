// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxCoins(int n,vector<vector<int>> &ranges){
        int res=0;
        sort(ranges.begin(), ranges.end(), [](const vector<int> &x, const vector<int> &y){return x[2]>y[2];});
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n;j++){
                if(ranges[i][1]<=ranges[j][0] || ranges[j][1] <= ranges[i][0]){ 
                    res < ranges[i][2] + ranges[j][2] ? res = ranges[i][2] + ranges[j][2]:1; 
                }
            }
        }
        return res> ranges[0][2] ? res: ranges[0][2];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> a(n,vector<int>(3));
        for(int i=0;i<n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        }
        Solution ob;
        cout<<ob.maxCoins(n,a)<<endl;
    }
    return 0;
}  // } Driver Code Ends