#include<bits/stdc++.h>
using namespace std;

// Generate all possible unique permutations of a given array 
// where array might contain duplicate elements

class Solution{
    public:
    vector<int> array;
    vector<vector<int>> result;
    void computePermutations(vector<int> tempArr){
        if(tempArr.size() != array.size()){
            //loop through all array elements and find the non occuring element
            for(int iter = 0; iter<array.size(); iter++){
                // If element already present in the array, do not call recursion
                if(find(tempArr.begin(), tempArr.end(), array[iter]) != tempArr.end()) continue;
                else if(iter>0 && array[iter] == array[iter-1]) continue;

                // Call backtracking with each element
                tempArr.emplace_back(array[iter]);
                computePermutations(tempArr);
                tempArr.pop_back();
            }
        }
        else result.emplace_back(tempArr);
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
    vector<int> array {1,2,1}, temp;
    Solution s;
    sort(array.begin(), array.end());
    s.array = array;
    s.computePermutations(temp);
    s.show2dVector(s.result);
}