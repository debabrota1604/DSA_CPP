#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<int> deg (n,0), oddDeg;
        for(int i=0; i<edges.size(); i++){
            deg[edges[i][0]-1]++; deg[edges[i][1]-1]++;
        }
        sort(deg.begin(), deg.end());
        for(int i=0; i<n; i++) if(deg[i]%2 ) oddDeg.emplace_back(deg[i]);
        if(oddDeg.size() ==1 || oddDeg.size() ==3 || oddDeg.size() >4) return false;
        return true;
        
        
    }
};