#include<bits/stdc++.h>
using namespace std;

int main(){
    int tc,n,t, res=0; cin>>tc;
    while(tc--){
        cin >>n; vector<int> a(n,0), a1,a0;
        for(int i=0; i<n; i++){
            cin >>a[i];
        }
        for(int i=0; i<n; i++){
            cin >>t;
            if(a[i]) a1.emplace_back(t);
            else a0.emplace_back(t);
        }
        sort(a0.begin(), a0.end());
        sort(a1.begin(), a1.end());

        if(a0.size() > a1.size()){
            res
        }
        else{

        }
    }




    return 0;
}