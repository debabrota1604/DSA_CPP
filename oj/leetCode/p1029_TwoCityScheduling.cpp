#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<int> diff; int minCost=0;
        //get the difference and add all users to be sent to city A.
        for(int i=0;i<costs.size();i++){
            minCost += costs[i][0]; //Adding city A cost
            
            // Storing diff in vector for easy sorting
            diff.emplace_back(costs[i][1] - costs[i][0])); 
        }
        
        //sort the vector to get least n elements to be directed to city B
        sort(diff.begin(), diff.end());
        
        //print, can be commented
        for(int i=0;i<costs.size();i++){
            cout << diff[i] << " ";
        }
        
        //Redirect selected n users with min difference to city B by adding the difference.
        for(int i=0;i<costs.size()/2;i++){ minCost += diff[i]; }
        
        return minCost;
    }
};