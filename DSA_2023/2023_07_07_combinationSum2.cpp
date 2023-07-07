#include<bits/stdc++.h>
using namespace std;

// Gets the arrays where sum consists of array elements considered only once
class Solution {
    vector<vector<int>> result;
    vector<int> candidates;
public:
    void dfs(int curInd, int target, vector<int> &tempSum){
        if(target == 0){
            result.emplace_back(tempSum);
            return;
        }
        
        for(int iter = curInd; iter < candidates.size(); iter++){
            // This check is special for this problem. 
            // if present candidate is equal to the last candidate, skip this call
            // This cannot be done later
            if(iter != curInd && candidates[iter]==candidates[iter-1]) continue;
            
            if(target-candidates[iter] >= 0){
                tempSum.emplace_back(candidates[iter]);
                dfs(iter+1, target-candidates[iter], tempSum);
                tempSum.pop_back();                
            }            
        }        
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> res;
        sort(candidates.begin(), candidates.end());
        show1dVector(candidates);
        this->candidates = candidates;
        dfs(0, target, res);
        return this->result;
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
    vector<int> c {10,1,2,7,6,1,1,5};
    int target = 9;

    cout << "Result: " << endl;
    s.show2dVector(s.combinationSum2(c,target));

    return 0;
}