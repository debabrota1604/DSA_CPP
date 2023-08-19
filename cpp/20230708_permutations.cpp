#include<bits/stdc++.h>
using namespace std;

// Generate all permutations of a given array where every element of the array is distinct

class Solution{
    public:
    vector<int> array;
    vector<vector<int>> result;


    void computePermutations(vector<int> tempArr){
        if(tempArr.size() ==  array.size()){
            result.emplace_back(tempArr);
            return;
        }

        for(int iter = 0; iter<array.size(); iter++){
            // If current element is present in the array then do not call recursion
            if(find(tempArr.begin(), tempArr.end(), array[iter]) != tempArr.end()) continue;

            // Else call the backtracking recursion call
            tempArr.emplace_back(array[iter]);
            computePermutations(tempArr);
            tempArr.pop_back();
        }
    }

    void computePowerSet(vector<int> tempSet, int index){
        if(index >= array.size()){
            result.emplace_back(tempSet);
            return;
        }

        computePowerSet(tempSet, index+1);
        tempSet.emplace_back(array[index]);
        computePowerSet(tempSet, index+1);
        tempSet.pop_back();
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

};


int main(){
    vector<int> array {1,2,3}, temp;
    Solution s;
    s.array = array;
    cout << "All posible permutations: ";
    s.computePermutations(temp);
    s.show2dVector(s.result);

    s.result.clear();
    temp.clear();

    cout << "Power Set: ";
    s.computePowerSet(temp,0);
    s.show2dVector(s.result);
}