#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j){
        // bounds check
        if(i<0 || i >= grid.size() || j<0 || j >= grid[0].size()) return;
        
        // recursion ends at water/discovered land
        if(grid[i][j] != '1') return;
        
        // change land type to discovered
        grid[i][j] = '2';
        
        // recursively find all neighbour lands to form big land
        dfs(grid, i-1,j);
        dfs(grid, i,j-1);
        dfs(grid, i+1,j);
        dfs(grid, i,j+1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int island = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                
                //scan through all indices for land
                if(grid[i][j] == '1'){
                    dfs(grid, i,j);
                    
                    // increment unique land counter
                    island++;
                }
            }
        }
        return island;
    }
};