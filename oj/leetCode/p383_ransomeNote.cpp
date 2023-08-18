#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> freq (26,0);
        for (auto i: magazine) {  freq[i-'a'] +=1;  }
        for (auto i: ransomNote) {  freq[i-'a'] -=1;  }
        for (auto i: freq) { if (i<0) return false;}
        return true;
    }
};

// Problem: Whether param1 can be constructed by taking letters from param2
// Algo:
// 1. define storage for 26 elements.
// 2. cout the frequency of letters in param2.
// 3. loop through param1, subtract the frequency of each letter in the frequency counter.
// 4. loop through freq counter, if any counter is less than zero, return false. else true.

int main(){
    Solution s;
    string ransomeNote = "b";
    string magazine = "ab";


    cout << s.canConstruct(ransomeNote, magazine) << endl;


    return 0;
}