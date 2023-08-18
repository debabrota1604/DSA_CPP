#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool withinTwoEdits(string x, string y){
        int change=0;
        for(int it=0; it<x.size(); it++) if(x[it] != y[it]) change++;
        if(change<=2) return true;
        else return false;
    }
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> res;
        for(int it1=0; it1<queries.size(); it1++)
            for(int it2=0; it2< dictionary.size(); it2++)
                if(withinTwoEdits(queries[it1], dictionary[it2])) {res.emplace_back(queries[it1]); break;}
        return res;
    }

    void printStrVec(vector<string> ss){
        for(auto s:ss) cout << s << " ";
        cout << endl;
    }
};




int main(){
    Solution s;
    vector<string> w1 = {"word","note","ants","wood"}, d1= {"wood","joke","moat"};
    vector<string> w2 = {"yes"}, d2= {"not"};


    s.printStrVec(s.twoEditWords(w1,d1));
    s.printStrVec(s.twoEditWords(w2,d2));





    return 0;
}