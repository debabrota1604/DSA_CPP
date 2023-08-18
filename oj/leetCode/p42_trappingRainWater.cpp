#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        //Step 1: Compute prefix and suffix array to get left and right bar heights
        vector<int> left (height.size(),0);
        vector<int> right (height.size(),0);
        
        int maxHeight = 0;
        for(int i=0;i<height.size();i++){
            maxHeight < height[i] ? maxHeight = height[i] :1;
            left[i] = maxHeight;
        }
        
        maxHeight = 0;
        for(int i=height.size()-1;i>=0;i--){
            maxHeight < height[i] ? maxHeight = height[i] :1;
            right[i] = maxHeight;
        }
        
        //Step 2: peer height is min of left and right heights.
        // If peer height is higher than actual height, then remaining diff must be water.
        int res =0, h;
        for(int i=0; i< left.size(); i++){
            h = min(left[i], right[i]);
            if(h > height[i]) res += h - height[i];
        }
        
        return res;
    }
};