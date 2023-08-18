#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int findMoves(int n, vector<int> chairs, vector<int> passengers) {
        int retVal;
        //sort each array for easy distance mapping
        sort(chairs.begin(), chairs.end());
        sort(passengers.begin(), passengers.end());

        for(int iter=0; iter<n; iter++){
            retVal += abs(chairs[iter] - passengers[iter]);
        }

        return retVal;
    }
};



int main(){
    //executed successfully at GFG test.

    return 0;
}