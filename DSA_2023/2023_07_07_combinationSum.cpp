#include<bits/stdc++.h>
using namespace std;

class Solution {
public:    
    vector<vector<int>> ans;
    vector<int> candidates;
     void dfs(int index, int target, vector<int> tempSum){
        cout << "Call stack: " << target << " ";
        show1dVector(tempSum);


        for(int iter = index; iter< this->candidates.size(); iter++){
            if(target == 0){
                ans.emplace_back(tempSum);
            }
            if(target - candidates[iter] >=0){
                tempSum.emplace_back(candidates[iter]);
                dfs(iter, target - candidates[iter], tempSum );
                tempSum.pop_back();
            }
        }        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> res;
        this->candidates = candidates;
        dfs(0, target, res);
        return ans;
    }

    void show2dVector(vector<vector<int>> v){
        cout << "[ ";
        for (int i=0; i< v.size(); i++){
            cout << "[";
            for (int j=0; j<v[i].size(); j++){
                cout << v[i][j] << ",";
            }
            cout << " ],";
        }
        cout << " ]" << endl;
    }

    void show1dVector(vector<int> v){
        cout << "[";
        for(int i=0; i<v.size();i++){
            cout << v[i] << ",";
        }
        cout << "]\n";
    }
};


int main(){
    Solution s;
    vector<int> c {2,3,6,7};
    int target = 7;

    cout << "Result: " << endl;
    s.show2dVector(s.combinationSum(c,target));
}