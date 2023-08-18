#include<bits/stdc++.h>
using namespace std;


class Solve{
    string s;
    char sep;
    vector<string> words;
    public:
    Solve(string inp, char seperator): s(inp), sep(seperator){}
    void tokenize(){
        vector<string> res;
        string tempWord ="";

        for(int iter=0; iter<s.size(); iter++){
            // Store character if it is not a seperator
            if(s[iter] != sep) tempWord += s[iter];

            // If seperator is found, store the nonempty buffer
            else if(tempWord.size() >0) res.emplace_back(tempWord);
        }

        words = res;
    }
    string getReversedWords(){
        tokenize();
        string res = "";
        for(int iter=0; iter<words.size(); iter++){
            res += words[iter];
            if(iter<words.size()-1) res += sep;
        }
        return res;
    }
};

int main(){
    string s = "The Sky is Blue";
    Solve solve(s,' ');
    cout << solve.getReversedWords() << endl;
}