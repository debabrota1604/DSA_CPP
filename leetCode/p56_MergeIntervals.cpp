#include<bits/stdc++.h>
using namespace std;

// Given an array of intervals where intervals[i] = [starti, endi], 
// merge all overlapping intervals, and return an array of the 
// non-overlapping intervals that cover all the intervals in the input.

// Example 1: Input: intervals = [[1,3],[2,6],[8,10],[15,18]] Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

// Example 2: Input: intervals = [[1,4],[4,5]] Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        //first, sort the intervals in ascending order of start index
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res; res.emplace_back(intervals[0]);

        for(int it=1; it<intervals.size(); it++){
            if(res[res.size()-1][1] >= intervals[it][0]){ 
                res[res.size()-1][1] = res[res.size()-1][1] > intervals[it][1] ? res[res.size()-1][1] : intervals[it][1];
            }
            else{
                res.emplace_back(intervals[it]);
            }
        }

        return res;
    }
    void dispVec2D(const vector<vector<int>>& vec){
        cout << "[" ;
        for(int i=0; i<vec.size(); i++){
            cout << "[";
            for(int j=0; j< vec[0].size(); j++){
                cout << vec[i][j] << " ";
            }
            cout << "]";
        }
        cout << "]\n\n";
    }
};


int main(){
    Solution s;
    vector<vector<int>> v1 {{1,3}, {2,6}, {8,10}, {15,18}};
    vector<vector<int>> v2 {{1,4}, {4,5}};

    cout << "Before: " ; s.dispVec2D(v1);
    v1 = s.merge(v1);
    cout << "After: "; s.dispVec2D(v1);

    cout << "Before: " ; s.dispVec2D(v2);
    v2 = s.merge(v2);
    cout << "After: "; s.dispVec2D(v2);


    return 0;
}