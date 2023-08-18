#include<bits/stdc++.h>
using namespace std;


int main(){
    int tc; cin>>tc;
    while(tc--){
        int sz;; cin>>sz; vector<int> ip(sz,0),fc;
        for(int i=0; i<sz; i++){
            cin>>ip[i];
        }
        sort(ip.begin(), ip.end()); vector<int> diff = ip;
        for(int i=1; i<sz; i++){
            diff[i] = ip[i] - ip[i-1]; 
        }
        int m1=diff[1],m2=diff[2];
        for(int i=1; i<sz; i++){
            if(diff[i] <= m1){m1=diff[i];m2=diff[i-1];}
        }
        cout << m1+m2 << '\n';
    }

}