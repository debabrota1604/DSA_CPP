#include<bits/stdc++.h>
using namespace std;

bool isLuxurious(int num){
    int d = sqrt(num); //flooring is implicit
    if(num%d ==0) return true;
    return false;
}

int main(){
    int tc,l,r;cin>>tc;
    while(tc--){
        cin >> l >> r; long long res=0;
        int lroot=sqrt(l), lLim = (lroot+1) * (lroot+1) ;
        for(int i=l;i<=r;i++){
            if(i == lLim){
                lroot++;
                lLim = (lroot+1) * (lroot+1);
            }
            if(i%lroot==0){ res++;}
        }
        cout << res << endl;
    }




    return 0;
}