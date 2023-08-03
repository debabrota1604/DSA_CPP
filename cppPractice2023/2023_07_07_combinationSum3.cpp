#include<bits/stdc++.h>
using namespace std;

/*
Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
    Only numbers 1 through 9 are used.
    Each number is used at most once.
Return a list of all possible valid combinations. 
The list must not contain the same combination twice, and the combinations may be returned in any order.

2 <= k <= 9
1 <= n <= 60
*/

class Solution {
    vector<vector<int>> res;
    int maxLen;
public:
    void dfs(vector<int> tempList, int tempLen, int tempIndex, int target){
        if(target == 0 && tempLen == maxLen){
            res.emplace_back(tempList);
            return;
        }
        if(tempLen == maxLen) return;

        for(int iter = tempIndex+1; iter<10; iter++){
            if(target - iter >=0){
                tempList.emplace_back(iter);
                dfs(tempList, tempLen +1, iter, target - iter);
                tempList.pop_back();
            }
        }
    }


    vector<vector<int>> combinationSum3(int k, int n) {
        maxLen = k;
        vector<int> tempList;
        dfs(tempList, 0, 0, n);
        return res;
    }

    void show2dVector(vector<vector<int>> v){
        cout << "[ ";
        for (int i=0; i< v.size(); i++){
            cout << "[";
            for (int j=0; j<v[i].size(); j++){
                cout << v[i][j];
                if(j!= v[i].size()-1) cout << ",";
            }
            cout << "]";
            if(i!= v.size()-1) cout << ", ";
        }
        cout << " ]" << endl;
    }

    void show1dVector(vector<int> v){
        cout << "[";
        for(int i=0; i<v.size();i++){
            cout << v[i];
            if(i!= v.size()-1) cout << ",";
        }
        cout << "]\n";
    }
};


int main(){
    Solution s;

    cout << "Result: " << endl;
    s.show2dVector(s.combinationSum3(4,20));

    return 0;
}