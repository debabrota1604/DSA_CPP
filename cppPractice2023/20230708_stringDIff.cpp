#include<bits/stdc++.h>
using namespace std;

// The problem is to find out the set of words that are present in s1 but not in s2.


class Solution{
    public:
    void dispStrVector(vector<string> s){
        for (int iter=0; iter<s.size(); iter++){
            cout << s[iter];
            if(iter != s.size()-1) cout << ",";
        }
        cout << endl;
    }

    vector<string> getWords(string s){
        int fi = 0, li=0;
        vector<string> res;
        for(int iter=0; iter<s.size(); iter++){
            if(s[iter] == ' '){
                if(li>0){
                    res.emplace_back(s.substr(fi, li));
                }
                fi = iter+1;
                li = 0;
            }
            else{
                li++;
            }
        }
        if(li>0){
            res.emplace_back(s.substr(fi, li));
        }
        return res;
    }
    vector<string> solve(string big, string small){
        vector<string> t1 = getWords(big),t2 = getWords(small), res;
        int iter1=0, iter2=0;
        while(iter2<t2.size()){
            while(iter1< t1.size()){
                if(t1[iter1].compare(t2[iter2]) ==0){
                    iter1++;
                    iter2++;
                }
                else{
                    res.emplace_back(t1[iter1]);
                    iter1++;
                }
            }
        }
        return res;
    }
};

int main(){
    string s1 = "I want to go  school and study coding & algorithms";
    string s2 = "I want to study algorithms";
    Solution s;
    s.dispStrVector(s.solve(s1, s2));


}