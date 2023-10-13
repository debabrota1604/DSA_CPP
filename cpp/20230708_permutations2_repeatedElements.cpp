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
                if(find(tempArr.begin(), tempArr.end(), array[iter]) == tempArr.end()) continue;

                // If current element is same as previous element, don't call recursion
                if(iter>0 && array[iter] == array[iter-1]) continue;

                // Call backtracking with each element
                tempArr.emplace_back(array[iter]);
                computePermutations(tempArr);
                tempArr.pop_back();
            }
        }
        else result.emplace_back(tempArr);
    }

    // Swap the current element with all remaining elements in the iteration and then restore.
    void optimizedPermutation(vector<int> arr, int index){
        if(index == arr.size()-1){
            result.emplace_back(arr);
            return;
        }

        for(int iter=index; iter<arr.size(); iter++){
            // Swap before recursion
            swap(arr[index], arr[iter]);

            //Recursion to subproblem
            optimizedPermutation(arr, index+1);

            //backtrack
            swap(arr[index], arr[iter]);
        }
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
    
    // O(n^2) backtracking based solution
    s.optimizedPermutation(array, 0);
    s.show2dVector(s.result);

    // Older solution
    s.result.clear();
    sort(array.begin(), array.end());
    s.array = array;
    s.computePermutations(temp);
    s.show2dVector(s.result);
}