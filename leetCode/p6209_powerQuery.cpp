#include<bits/stdc++.h>
using namespace std; 
 
#define LL long long
#define LD long double
#define CY cout<<"YES\n"
#define CN cout<<"NO\n"
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
    vector<bool> getBin(int num){
        vector<bool>  res;
        while(num>0){
            if(num%2==0) res.emplace_back(false);
            else res.emplace_back(true);
            num/=2;
        }
        reverse(res.begin(),res.end());
        return res;
    }
    void dispBin(vector<bool> b){
        for(int i=0; i<b.size();i++){
            if(b[i]) cout << "1 ";
            else cout << "0 ";
        }
        cout << endl;
    }
    void dispInt(vector<int> b){
        for(int i=0; i<b.size();i++){
            cout << b[i] << " ";
        }
        cout << endl;
    }
    vector<int> powVec(vector<bool> bin){
        int pw=1; vector<int> res;
        for(int it=bin.size()-1;it>=0;it--){
            if(bin[it]) res.emplace_back(pw);
            pw*=2;
        }
        return res;
    }
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> res,powV = powVec(getBin(n));
        for(auto q:queries){
            long long mul=1;
            for(int lo=q[0];lo<=q[1];lo++){
                mul*=powV[lo];
                mul%=(long long)(1e9+7);
            }
            res.emplace_back(mul);
        }
        return res;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // int tc;cin>>tc;
    // while(tc--){

    // }
    Solution s; vector<vector<int>> v1 {{0,1},{2,2},{0,3}}, v2 {{0,0}};
    // s.dispInt(s.powVec(s.getBin(15)));
    // s.dispInt(s.powVec(s.getBin(2)));
    s.dispInt(s.productQueries(15,v1));
    s.dispInt(s.productQueries(2,v2));

       
    return 0;
}
