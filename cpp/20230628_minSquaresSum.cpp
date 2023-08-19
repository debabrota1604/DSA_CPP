#include<bits/stdc++.h>
using namespace std;

class MinSquareSum{
    unordered_map<int,int> memo;
    public:
    unsigned int countMinSquaresToSum(int sum){
        if(sum == 0) return 0;
        if(sum == 1) return 1;

        if(memo.find(sum) != memo.end()) return memo[sum];

        unsigned int res=UINT_MAX;
        for(int iter =1; iter*iter <= sum; iter++){
            res = min( res, countMinSquaresToSum(sum - iter*iter)+1);
        }
        memo[sum] = res;
        return res;
    }
};


class MinSquaresIterative{
    public:
    int computeMinSquareSum(int sum){
        // Base case
        vector<int> memory (sum+1, INT_MAX);
        memory[0] = 0;
        memory[1] = 1;

        for(int iter=2; iter <= sum; iter++){
            for(int iter2=1; iter2*iter2 <= sum; iter2++){
                memory[iter] = min( memory[iter] , memory[iter - iter2*iter2]+1 );
            }
        }
        return memory[sum];
    }
};



int main(){
    MinSquareSum mss;
    int sum =10;

    cout << "Minimum squares to sum up " << sum << " is " << mss.countMinSquaresToSum(sum) << endl;

    MinSquaresIterative msi;

    cout << "Minimum squares to sum up " << sum << " is " << msi.computeMinSquareSum(sum) << endl;
}