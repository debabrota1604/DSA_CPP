#include<bits/stdc++.h>
using namespace std;

int gcd(int m,int n){
    int a=m,b=n;
    while(b>0){int temp=a%b;a=b;b=temp;}
    return a;
}

int main(){
    int tc,sz,x,i,j,sum;cin>>tc;
    while(tc--){
        cin>>sz;vector<int> v (sz,0); bool res=false;
        for(i=0;i<sz;i++){ cin>>x; v[i]=x;}
        for( i=sz-1;i>=0;i--){
            for( j=i; j>=0;j--){
                if(gcd(v[i],v[j])==1 && i+j+2>sum){  sum=i+j+2; res=true; }
            }
        }
        if(res) cout << sum << "\n";
        else cout << "-1\n";
        sum=0;
    }

}