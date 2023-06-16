#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    vector<string> avoidExplosion(vector<vector<int>> mix, int n, vector<vector<int>> danger, int m) {
        vector<string> ans;
        
        for(auto item1:mix){
            bool fl=true;
            for (auto item2:danger){
                if ( item1[0] == item2[0] && item1[1] == item2[1]) fl = false;
                
            }
            if(fl)
                ans.push_back("Yes");
            else
                ans.push_back("No");
        }
    
        return ans;
    }
};