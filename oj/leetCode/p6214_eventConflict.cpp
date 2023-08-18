#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        string s1 = event1[0],s2 = event2[0], e1=event1[1];
        bool isDisj = e1[0] < s2[0] || ((e1[0] == s2[0]) && e1[1] < s2[1]) || (e1[0] == s2[0] && e1[1] == s2[1] && e1[3] < s2[3]) || (e1[0] == s2[0] && e1[1] == s2[1] && e1[3] == s2[3] && e1[4] < s2[4]);
        bool e1First=(s1[0] < s2[0]) || (s1[0] == s2[0] && s1[1] < s2[1]) || (s1[0] == s2[0] && s1[1] == s2[1] && s1[3] < s2[3]) || (s1[0] == s2[0] && s1[1] == s2[1] && s1[3] == s2[3] && s1[4] < s2[4]);
        if(e1First){
            return !isDisj;
        }
        else{
            auto temp = event1; event1=event2; event2=temp; s1 = event1[0],s2 = event2[0], e1=event1[1];
            isDisj = e1[0] < s2[0] || ((e1[0] == s2[0]) && e1[1] < s2[1]) || (e1[0] == s2[0] && e1[1] == s2[1] && e1[3] < s2[3]) || (e1[0] == s2[0] && e1[1] == s2[1] && e1[3] == s2[3] && e1[4] < s2[4]);

            return !isDisj;
        }
    }
};




int main(){
    Solution s;
    vector<string> e1 = {"01:15","02:00"}, e2 = {"02:00","03:00"},
    e3 = {"01:00","02:00"}, e4 = {"01:20","03:00"},
    e5 = {"10:00","11:00"}, e6 = {"14:00","15:00"},
    e7= {"14:13","22:08"}, e8={"02:40","08:08"},
    e9={"16:53","19:00"}, e10={"10:33","18:15"};

    cout << s.haveConflict(e1,e2) << endl;
    cout << s.haveConflict(e3,e4) << endl;
    cout << s.haveConflict(e5,e6) << endl;
    cout << s.haveConflict(e7,e8) << endl;
    cout << s.haveConflict(e9, e10) << endl;

    return 0;

}