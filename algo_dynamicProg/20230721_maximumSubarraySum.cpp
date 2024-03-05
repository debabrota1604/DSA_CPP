#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> inp, int target, int index){
    //Base Case
    if(target == 0) return 0;
    if(index == -1) return -1; //target not zero and no element left to scan  

    int op1,op2;
    op1 = solve(inp, target, index-1);
    op2 = solve(inp, target - inp[index], index-1);

    if(op1 == -1 && op2 >=0) return op2+1;
    else if(op2 == -1 && op1 >=0) return op1;
    else if(op1 != -1 && op2 != -1) return max(op1, op2+1);
    else return -1;
}

int main(){
    cout << "Result 1:" << solve({2,3,5,5}, 10, 3) << endl;
    cout << "Result 2:" << solve({3,3,3}, 5, 2) << endl;
    
}