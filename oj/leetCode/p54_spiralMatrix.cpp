#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int left, right, up, down;
        left =0;
        up=0;
        right = matrix[0].size()-1;
        down = matrix.size()-1;
        
        while(true){
            for(int iter=left; iter<=right; iter++) res.emplace_back(matrix[up][iter]);
            up++;
            if(left > right || up > down) break;
            
            for(int iter = up; iter <= down; iter++) res.emplace_back(matrix[iter][right]);
            right--;
            if(left > right || up > down) break;
            
            for(int iter = right; iter >= left; iter--) res.emplace_back(matrix[down][iter]);
            down--;
            if(left > right || up > down) break;
            
            for(int iter = down; iter >= up; iter--) res.emplace_back(matrix[iter][left]);
            left++;
            if(left > right || up > down) break;
        }
        return res;
    }
};