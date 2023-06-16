#include<bits/stdc++.h>
using namespace std;

/*
Given a string s, remove duplicate letters so that every letter appears once and only once. 
You must make sure your result is the smallest in lexicographical order among all possible results.

Input: s = "bcabc", Output: "abc"
Input: s = "cbacdcbc", Output: "acdb"
*/


class Solution {
public:
    string removeDuplicateLetters(string s) {
        std::unordered_set<char> charSet; string s2=""; char c='z'; int min=0;
        for(int i=0; i<s.size(); i++){ if(s[i] < c ){c=s[i]; min=i;}}
        for(int i=min; i<s.size()+min; i++){
            charSet.emplace(s[i%s.size()]); 
        }
        for(auto i:charSet){
            cout << i << " "; s2=char(i)+s2;
        }
        
        return s2;
    }
};