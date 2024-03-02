#include<bits/stdc++.h>
using namespace std;


class Solution {
    int sz;
    unordered_map<int, int> mp;
public:
    int digit(char ch){ return ch == '*' ? -1 : ch - '0';}

    int solve(string s, int step){
        if(step >= sz) return 0;
        if(digit(s[step]) == 0) return 0;
        if(step +1 <sz){
            if(digit(s[step]) <3){
                if(digit(s[step+1]) == 0) return solve(s, step+2);
                else if(digit(s[step+1]) == -1) return 9 * solve(s, step+2);

            }
        }

        if(s[step])
    }
    int numDecodings(string s){
        return solve(s, 0);
    }
};


int main(){
    string s1 = "*";
    Solution s;
    cout << s.numDecodings(s1) << endl;
    return 0;
}