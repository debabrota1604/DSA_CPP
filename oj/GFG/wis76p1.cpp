// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int powerfullInteger(int n,vector<vector<int>> &intervals,int k){
        map<int,int> mp;
        for(int iter=0;iter<intervals.size(); iter++)
            for(int iter2=intervals[iter][0];iter2<=intervals[iter][1]; iter2++)
                mp[iter2]++;
        for(auto iter=mp.rbegin(); iter!=mp.rend(); iter++){
            if(iter->second >=k) return iter->first;
        }
        return -1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n;
        vector<vector<int>> intervals(n,vector<int>(2));
        for(int i=0;i<n;i++){
            cin>>intervals[i][0]>>intervals[i][1];
        }
        cin>>k;
        Solution ob;
        cout<<ob.powerfullInteger(n,intervals,k)<<endl;
    }
    return 0;
}  // } Driver Code Ends