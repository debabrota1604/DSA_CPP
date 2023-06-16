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
 
 
bool sortbysec(const pair<LL,LL> &a,const pair<LL,LL> &b)
{ return (a.second < b.second); }
 
int power(int a){   
    int ans=0;
    while(a>1)
    { a/=2;ans++; }
    return ans;    
}
 
class Solution {
public:
    int countTime(string time) {
        int r1=1,r2=1,r3=1,r4=1;
        if(time[4] =='?') r4=10;
        if(time[3] =='?') r3=6;
        if(time[1] =='?'){
            if(time[0] =='1' || time[0] =='0') r2=10;
            else if (time[0] =='2') r2=4;
            else r2=12;
        }
        if(time[0] =='?'){
            if(time[1] =='0' || time[1] =='1' || time[1] =='2' || time[1] =='3') r1=3;
            else if(time[1] =='4' || time[1] =='5' || time[1] =='6' || time[1] =='7'|| time[1] =='8' || time[1] =='9') r1=2;
            else r1=2;
        }
        cout << r1 << " " << r2 << " " << r3 << " " << r4 << " " << endl;
        return r1*r2*r3*r4;
        
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // int tc;cin>>tc;
    // while(tc--){
    // }

    Solution s;
    cout << s.countTime("0?:0?") << endl;
    cout << s.countTime("??:??") << endl;
    cout << s.countTime("2?:??") << endl;
       
    return 0;
}
