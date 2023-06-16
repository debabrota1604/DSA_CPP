#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int longestContinuousSubstring(string s) {
        int res=1, max=1;
        for(int i=1; i<s.size(); i++){
            if(s[i]-'a' == s[i-1]-'a'+1) res +=1;
            else res=1;
            cout << i << " " << res << endl;
            if(res>max) max=res;
        }
        return max;
    }
};


int main(){
    Solution s;
    cout << s.longestContinuousSubstring( "yrpjofyzubfsiypfre" ) << endl;


    return 0;
}