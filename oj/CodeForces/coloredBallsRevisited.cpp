#include<bits/stdc++.h>
using namespace std;


int main(){
    int tc, inp1, maxNum=0, maxOdd=0, maxeven=0; cin>>tc;
    while(tc--){
        cin >> inp1; vector<int> balls (inp1, 0), b2;
        for(int i=0;i<inp1; i++){
            cin >> balls[i];
            if (balls[i]%2==0 && balls[i]>balls[maxeven]) maxeven = i;
            if (balls[i]%2==1 && balls[i]>balls[maxOdd]) maxOdd = i;
            if (balls[i]>maxNum) maxNum = balls[i];
        }
        if (balls[maxOdd] == maxNum) cout << "\t" << maxOdd+1 << endl;
        else cout << "\t" << maxeven+1 << endl;
        maxNum=0; maxOdd=0; maxeven=0;
    }


    return 0;
}