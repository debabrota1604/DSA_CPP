#include<bits/stdc++.h>
using namespace std; 
 
#define LL long long
#define LD long double
#define CY cout<<"YES\n"
#define cCNn cout<<"NO\n"
#define PR pair<int,int>
 
// 48-57 -> 0-9
// 65-90 -> A-Z
// 97-122 -> a-z

int getMax(vector<int> num, int lo, int hi){
    int res=INT_MIN;
    for(int it=lo; it<hi; it++)
        if(num[it]>res) res=num[it];
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc,x,op;cin>>tc;
    while(tc--){
        cin>>x>>op;
        vector<int> v (x,0),vNew;
        for(int it=0; it<x; it++){
            cin>>v[it];
        }
        while(op--){
            if(v.size()>k)
        }
    }
       
    return 0;
}
