#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<class T> using indexed_set = tree<T, null_type, less<T>, 
            rb_tree_tag, tree_order_statistics_node_update>;
 
 
#define ll long long
#define ld long double
#define cy cout<<"YES\n"
#define cn cout<<"NO\n"
#define int int64_t
#define sp << ' ' <<
#define nl << '\n'
#define pii pair<int,int>
 
// 48-57 -> 0-9
// 65-90 -> A-Z
// 97-122 -> a-z
 
 
bool sortbysec(const pair<ll,ll> &a,const pair<ll,ll> &b)
{ return (a.second < b.second); }
 
int power(int a){   
    int ans=0;
    while(a>1)
    { a/=2;ans++; }
    return ans;    
}
 
ll fastpow(ll a, ll b, ll m){
    if(b==0)return 1;
    if(b%2==0)    {
        ll take=fastpow(a,b/2,m);
        return (take*take)%m;
    }
    else    {
        ll take=fastpow(a,b-1,m);
        return (a*take)%m;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //OR
    cin.tie(0)->sync_with_stdio(0);

    
    // freopen("haybales.in", "r", stdin);
    // freopen("haybales.out", "w", stdout);
    int cases=1;
    cin>>cases;
    // Error can be because you didn't input the entreies
    
    /*
        Your code here
    */
    
    // minimise distance in a matkjrix, make a queue with the source and check for adjacent cells
    // max/min problem ?? try to solve using binary search
    // find result in form of mod ?? never use divide operation
    
    return 0;
}
