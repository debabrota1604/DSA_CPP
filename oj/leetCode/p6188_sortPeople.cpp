#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int, string> mp; vector<string> res (names.size(),-1);
        for(int i=0;i<names.size();i++){
            mp[heights[i]] = names[i];
        }
        for(int i=0;i<names.size();i++){
            res[i] = mp[i];
        }
        return res;
    }
};


int main(){



}