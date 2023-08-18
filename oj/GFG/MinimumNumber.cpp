// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minimumNumber(int n,vector<int> &arr){
        // Code here
        if(arr.size() ==1) return arr[0];
        priority_queue<int> pq; int data1, data2;
        for(auto item:arr){
            pq.emplace(item);
        }
        for(int i=0; i<pq.size(); i++){
            data1 = pq.top(); pq.pop();
            data2 = pq.top(); pq.pop(); 
            if( data1 >= data2) {pq.emplace(data2); pq.emplace(data1-data2);}
            else break;
        }
        return data1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.minimumNumber(n,arr)<<endl;
    }


    return 0;
}  // } Driver Code Ends