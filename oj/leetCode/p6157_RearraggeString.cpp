#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        bool modify=false; int replaceCount; string temp;

        for (replaceCount=0;replaceCount<s.size();replaceCount++){
            modify = false; temp = s;
            for (int i=0;i<s.size()-1;i++){
                if (s[i]=='0' && s[i+1]=='1'){
                    temp[i] = '1'; temp[i+1]='0';
                    modify = true;
                }
            }
            s = temp;
            if (modify == false)
                break;
        }
        return replaceCount;
    }
};



int main(){
    Solution s;

    cout << s.secondsToRemoveOccurrences("0110101") << endl;



    return 0;
}