#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string res (s.size(),'a');
        for (int i=0; i<s.size(); i++){
            res[indices[i]] = s[i];
        }

        return res;
    }
};



int main(){
    vector<int> v {4,5,6,7,0,2,1,3};
    Solution s; 
    cout << s.restoreString("codeleet", v) << endl;


    return 0;
}