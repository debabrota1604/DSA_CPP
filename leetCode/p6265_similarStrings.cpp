#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int similarPairs(vector<string>& words) {
        vector<set<char>> wordSet; int res;
        for(int i=0; i<words.size();i++){
            set<char> temp;
            for(int j=0; j<words[i].size(); j++) temp.emplace(words[i][j]);
            wordSet.emplace_back(temp);
        }
        for(int i=0; i<wordSet.size(); i++){
            for(int j=i; j<wordSet.size(); j++){
                if(wordSet[i] == wordSet[j]) res++;
            }
        }
        return res;
    }
};