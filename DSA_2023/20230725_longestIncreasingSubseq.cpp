#include<bits/stdc++.h>
using namespace std;

unordered_map<int, unordered_map<int, int>> memory;

int solve(vector<int> arr, int currIndex, int maxIndex){
    //cout << currIndex << ":" << maxIndex << endl;
    if(currIndex >= arr.size()) return 0;

    int op1, op2, maxVal;
    op1 = op2 = INT_MIN;
    maxIndex == -1 ? maxVal = -1:maxVal = arr[maxIndex];

    if(arr[currIndex] > maxVal) op1 = solve(arr, currIndex +1, currIndex) +1;
    op2 = solve(arr, currIndex +1, maxIndex);

    return max(op1, op2);
}

int solveMemoization(vector<int> arr, int currIndex, int maxIndex){
    if(currIndex >= arr.size()) return 0;
    if(memory.find(currIndex) != memory.end() && memory[currIndex].find(maxIndex) != memory[currIndex].end()) return memory[currIndex][maxIndex];

    int op1, op2, maxVal;
    op1 = op2 = INT_MIN;
    maxIndex == -1 ? maxVal = -1:maxVal = arr[maxIndex];

    if(arr[currIndex] > maxVal) op1 = solve(arr, currIndex +1, currIndex) +1;
    op2 = solve(arr, currIndex +1, maxIndex);

    memory[currIndex][maxIndex] =  max(op1, op2);
    return memory[currIndex][maxIndex];
}

int main(){
    cout << "Res: " << solve({0,1,4,7,6,9},0, -1) << endl;
    cout << "Res: " << solve({0,2,1,7,6,9},0, -1) << endl;
    cout << "Res: " << solve({1,2,4,7,6,9},0, -1) << endl;
    cout << "Res: " << solve({1,3,4,7,6,9},0, -1) << endl;
    cout << "Res: " << solve({2,1,4,3,6,5,8,7,10,9, 11},0, -1) << endl;
}