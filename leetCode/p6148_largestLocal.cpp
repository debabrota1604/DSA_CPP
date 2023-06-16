#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution{
    public:
    int maxEl(int i1, int i2, int i3, int i4,int i5, int i6, int i7, int i8, int i9){
        vector<int> v {i1,i2,i3,i4,i5,i6,i7,i8,i9};
        auto mEl = max_element(v.begin(),v.end());
        return int(*mEl);
    }

    vector<vector<int>> largestLocal ( vector<vector<int>>& grid){
        int llRow = (grid[0]).size(),llCol = grid.size();
        vector<int> ll(llCol-2);        
        vector<vector<int>> llMat;
        for (auto i=0; i<llRow-2; i++){
            llMat.emplace_back(ll);
        }

        for (auto i=1; i < llRow-1; i++){
            for (auto j=1; j<llCol-1; j++){
                llMat[i-1][j-1] = maxEl(grid[i-1][j-1],grid[i-1][j], grid[i-1][j+1],
                            grid[i][j-1],grid[i][j], grid[i][j+1],
                            grid[i+1][j-1],grid[i+1][j], grid[i+1][j+1]);
            }
        }

        return llMat;
    }
};


int main(){
    Solution s;
    vector<vector<int>> g {{1,1,1,1,1},
                            {1,1,1,1,1},
                            {1,1,1,1,1},
                            {1,1,1,1,1},
                            {1,1,1,1,1}};
    s.largestLocal(g);
    return 0;
}