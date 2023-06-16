#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string robotWithString(string s) {
        if(s=="") return "";
        string res="",rev;int minInd=0;
        for(int i=1; i<s.size(); i++){
            if(s[i]<s[minInd] ){
                minInd = i;
            }
        }
        rev = s.substr(0, minInd+1); reverse(s.begin(), s.begin()+minInd+1);
        res = s[0] + robotWithString(s.substr(1));
        return res;
    }
};



int main(){

    Solution S; string s1 = "zza", s2= "bac", s3= "bdda", s4 = "bydizfve";
    cout << S.robotWithString(s1) << endl;
    cout << S.robotWithString(s2) << endl;
    cout << S.robotWithString(s3) << endl;
    cout << S.robotWithString(s4) << endl;

    return 0;
}