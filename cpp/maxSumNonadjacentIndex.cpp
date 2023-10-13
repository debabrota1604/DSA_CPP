#include<iostream>
#include<vector>
using namespace std;

//Given an array of integer numbers, find the maximum sum of elements where none of the choosen elements are adjacent in the array.
int solve(vector<int>& input, int index, int tempSum){
    // Base case
    if(index == input.size()-1) return tempSum + input[index];
    else if(index >= input.size()) return 0;

    // Recursion Step
    int op1 = solve(input, index+1, tempSum);
    int op2 = solve(input, index+2, tempSum + input[index]);
    return max(op1, op2);
}

int main(){
    vector<int> input {2,4,2,7,5,10,55};

    cout << solve(input, 0, 0) << endl;


    return 0;
}