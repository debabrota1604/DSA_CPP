#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    string decodeAtIndex(string s, int k) {
        string res="";
        for(int iter=0; iter<s.size(); iter++){
            if( (int) s[iter]< 60){
                int count = s[iter] -'0';
                string temp="";
                while(count>0){
                    temp+=res;
                    count--;
                }
                res = temp;
            }
            else{
                res+=s[iter];
            }
            if(res.size() > k-1){
                return string(1, res[k-1]);
            }
            // if(res.size()>256){
            //     string res2 = res.substr(256);
            //     k-=256;
            //     res2 = res;
            // }
        }
        return string(1, res[k-1]);
    }
};


int main(){
    Solution s;


    cout << s.decodeAtIndex("leet2code3", 10) << endl;
    cout << s.decodeAtIndex("ha22", 5) << endl;
    cout << s.decodeAtIndex("a2345678999999999999999", 1) << endl;
    cout << s.decodeAtIndex("y959q969u3hb22odq595", 222280369) << endl;
    cout << s.decodeAtIndex("a2b3c4d5e6f7g8h9" ,69280) << endl;



}