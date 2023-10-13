#include<bits/stdc++.h>
using namespace std;

// Generate all permutations of a given array where every element of the array is distinct

class Solution{
    public:
    vector<int> array;
    vector<vector<int>> result;

    void swap(int& a, int& b){
        int temp = a;
        a = b;
        b = temp;
    }

    // Basic way: Check presence for a character and if exists, dont call recursion. O(n) extra time needed to check.
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
    
    // Swap the character with its neighbour using Heap's algorithm for generating permutations
    // Speciality: Only one swap per iteration.
    void heapPermutation(std::vector<int>& arr, int size) {
        if (size == 1) {
            // We have a permutation to print
            result.emplace_back(arr);
            return;
        }

        // Generate permutations for i-th swapped with each i-1 initial
        for (int i = 0; i < size; i++) {
            // generate permutations with k-th element unaltered
            heapPermutation(arr, size - 1);

            // If size is odd, swap the first and last element
            if (size % 2 == 1) {
                std::swap(arr[0], arr[size - 1]);
            } 
            else { // If size is even, swap the i-th and last element
                std::swap(arr[i], arr[size - 1]);
            }
        }
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
    cout << "All posible permutations optimal algo: ";
    s.heapPermutation(array, array.size());
    s.show2dVector(s.result);

    s.result.clear();
    cout << "All posible permutations Deb's optimal algo: ";
    s.optimizedPermutation(array, 0);
    s.show2dVector(s.result);

    s.result.clear();
    temp.clear();

    cout << "Power Set: ";
    s.computePowerSet(temp,0);
    s.show2dVector(s.result);
}