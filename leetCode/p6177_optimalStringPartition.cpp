#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int partitionString(string s) {
        string temp=""; int res=0;
        for(auto ch:s){
            if (temp.find(ch) == string::npos){
                temp += ch;
            }
            else{
                cout << temp << " "; temp =ch; res++;
            }
        }
        cout << temp << endl;
        return res+1; //last string to count
    }
};



int main(){
    Solution s;
    string str = "sssssssss";
    cout << s.partitionString(str) << endl;



    return 0;
}