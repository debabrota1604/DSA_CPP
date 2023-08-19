#include<bits/stdc++.h>
using namespace std;

class Solution {
    string s;
public:
    string solve(int st, int ed){
        //debugPrints
        cout << st << ":" << ed << endl;

        string res="";

        //Base case: odd palindrome
        if(st == ed) return res + s[st];

        // Base case: even palindrome
        if(st == ed-1 && s[st] == s[ed]) return res + s[st] + s[ed];
        if(st == ed-1 && s[st] != s[ed]) return res;

        if(s[st] == s[ed]){
            string res = solve(st+1, ed-1);
            string s1 = solve(st+1, ed);
            string s2 = solve(st, ed-1);
            if(res.size() >= s1.size() && res.size() >= s2.size()) return s[st]+res+s[ed];
            if(s1.size() >= res.size() && s1.size() >= s2.size()) return s1;
            if(s2.size() >= res.size() && s2.size() >= s1.size()) return s2;
            else return "";
        }
        else{
            string s1 = solve(st+1, ed);
            string s2 = solve(st, ed-1);
            if(s1.size() >= s2.size() && s1.size() >0) return s1;
            if(s2.size() >= s1.size() && s2.size() >0) return s2;
            return "";
        }
    }
    string longestPalindrome(string s) {
        this->s = s;
        if(s.size() == 2 && s[0] != s[1]) {
            string res = "";
            res+= s[0];
            return res;
        }
        return solve(0, s.size()-1);
    }

    string longestPalindrome2(string s) {
        int left=0, right=1, resStart=0, resLen=1, leng = s.size();
        if (leng <=1) return s;
        for(int mid=0; mid<leng;){
            left = right = mid;
            while(right<leng && s[right] == s[right+1]) right++;
            mid = right+1;
            while(left>0 && right<leng && s[left-1]==s[right+1]){ left--; right++;}
            if ((right-left+1) > resLen){ resStart = left; resLen=right-left+1; }
        }
        return s.substr(resStart,resLen);
    }
};


int main(){
    Solution s;
    cout << s.longestPalindrome("babad") << endl;
    cout << s.longestPalindrome("cbbd") << endl;
    cout << s.longestPalindrome("ab") << endl;
    cout << s.longestPalindrome("aacabdkacaa") << endl;

}