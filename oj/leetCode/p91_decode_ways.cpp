#include<bits/stdc++.h>
using namespace std;
/*
// 11106 = 1_1_10_6, 11_10_6

//226: 2_2_6, 22_6, 2_26
*/

class Solution{
    public:
    unordered_map<int, int> mp;
    int solve(string s, int step){
        if(step >= s.size()) return 1;
        else if(s[step] == '0') return 0;
        if(mp.find(step) != mp.end()) return mp.at(step);
        int res=0;

        if(s[step] -'0' >2) res= solve(s,step+1);
        else{
            if (step + 1 < s.size() && s[step + 1] > '0') {
                res = solve(s, step + 1);
                if (step + 2 < s.size() && stoi(s.substr(step, 2)) <= 26) {
                    res += solve(s, step + 2);
                }
            }
            else res= solve(s, step +2); // only one way for 10 & 20 case.
        }
        mp[step] = res;
        return res;
    }
    int numDecodings(string s){
        return solve(s, 0);
    }
};


int main(){
    Solution s;
    cout << s.numDecodings("06") << endl;

    return 0;
}