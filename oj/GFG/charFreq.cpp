#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<string> count(int n, string s) {
        // code here
        vector<int> temp; vector<string> res;
        for(int i=0; i<s.size(); i++){
            if(i==0 || s[i] != s[i-1]) temp.emplace_back(-1);
            if(s[i]==s[i-1]) temp.emplace_back(temp[i-1]+ 1);
        }
        char mc='a',cc='a';int mcc,ccc;
        for(int i=0; i<s.size(); i++ ){
            if(temp[i]==-1){ cc=s[i]; ccc=0;}
            else{ ccc++; }
            if(ccc>mcc){ mc=cc;mcc=ccc; }
        }
        string s1 (1,mc), s2 = to_string(mcc);
        res.emplace_back(s1); res.emplace_back(s2);
        return res;
    }
};

int main(){



}