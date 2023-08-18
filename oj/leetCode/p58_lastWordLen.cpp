#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int st=s.size()-1, en=0;
        
        //reach the last non-space index
        while(s[st--] == ' ');   en=st+1; st++;
        
        //reach where the next space is found
        while(en>=0 && s[en--] != ' '); en++; 
        
        return st-en+1;
    }
};

int main(){
    Solution s;
    string s1= "Hello World", s2 = "   fly me   to   the moon  ", s3= "luffy is still joyboy", s4 = "a";
    // cout << s1 << " " << s.lengthOfLastWord(s1) << endl;
    // cout << s2 << " " <<  s.lengthOfLastWord(s2) << endl;
    cout << s3 << " " <<  s.lengthOfLastWord(s3) << endl;
    cout << s4 << " " <<  s.lengthOfLastWord(s4) << endl;

    return 0;
}