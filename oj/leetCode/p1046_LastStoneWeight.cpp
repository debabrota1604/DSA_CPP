#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int max1 = stones[0], max2 = stones[1];
        if(sizeof(stones)>1){
            for(auto i=stones.begin();i!=stones.end();i++){
                if (*i > max1){
                    max2 = max1;
                    max1 = *i;
                    
                }
            }




        }
        if(stones.empty()) 
            return 0;
        else
            return stones[0];
        
    }
};