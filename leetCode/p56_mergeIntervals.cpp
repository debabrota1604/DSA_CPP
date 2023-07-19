#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    static bool comparator(vector<int> p1, vector<int> p2){
        return p1[0] < p2[0];
    }

    void disp(vector<vector<int>> v){
        cout << "[";
        for(int i=0; i< v.size(); i++){
            cout << "[";
            for(int j=0; j < v[0].size(); j++){
                cout << v[i][j] << " ";
            }
            cout << "]"; 
        }
        cout << "]\n";
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        //Step1: Sort the intervals based on starting indices
        sort(intervals.begin(), intervals.end(), comparator);
        
        vector<vector<int>> res;
        int iter=0, iter2=0;
        
        //Step2: Run two loops to compare two intervals
        while(iter < intervals.size()){
            
            vector<int> temp = intervals[iter];
            iter2 = iter+1;
            
            while(iter2 < intervals.size()){

                if(intervals[iter2][1] <= temp[1]){
                    
                }
                
                // If start of second interval is greater than finish time of first interval, they cannot be merged. 
                if(intervals[iter2][0] > temp[1]){
                    res.emplace_back(temp);
                    iter = iter2;
                    break;
                }
                // Else extend the present interval's finish time to include second interval
                temp[1] = max(temp[1], intervals[iter2][1]);
                iter2++;
            }
            if(iter2 == intervals.size()){
                res.emplace_back(temp);
                iter++;
            }
        }
        
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> v = {{1,3},{2,6},{8,10},{15,18}};
    s.disp(s.merge(v));
    vector<vector<int>> v2 = {{1,2},{2,5},{3,5},{4,5}};
    s.disp(s.merge(v2));
    
}