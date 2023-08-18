#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        //get max string size;
        int maxSize=0;
        for(auto i: words) maxSize  = maxSize > i.size() ? maxSize:i.size();

        set<string> s {};
        vector<vector<string>> wordPrefix {maxSize, s}; vector<int> res(words.size(),0);

        for(int i=0; i<words.size(); i++)
            for(int j=0; j<words[i].size();j++)
                wordPrefix[j].emplace_back(words[i].substr(0,j)); //insert j-len str on j-th set

        for(int i=0; i<words.size(); i++) //get all words
            for(int j=0; j<wordPrefix[i].size();j++) // all prefix of i-th str
            {
                string prf = words[i].substr(0,j);
                for(int k=0; k<maxSize; k++) // check for all len
                {
                    if(wordPrefix)
                }
            }
                    

        return res;
        
    }
};

int main(){
    Solution s;
    vector<string> v1 {"abc","ab","bc","b"};
    
    cout << s.sumPrefixScores(v1) << endl;

    return 0;
}