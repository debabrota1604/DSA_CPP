#include<bits/stdc++.h>
using namespace std;

// Given three integers lo, hi and target, find two integers a & b
// such that lo <= a < b <= hi and a^b <=k and a^b is maximum among all possibilities
// compute and return a^b.

class Solution{
    public:
    int solve(int lo, int hi, int target){
        int tempRes=0, maxRes =0;
        for(int iter1 = target; iter1>0; iter1--){
            for(int iter2 = hi; iter2>=lo; iter2--){
                tempRes = iter1^iter2;
                    cout << iter1 << ":" << iter2 << "=" << tempRes<< endl;
                if(tempRes>=lo && tempRes<=hi){
                    iter1>maxRes ? maxRes = iter1 :1;
                }
            }
        }
        return maxRes;
    }
};

int main(){
    int lo=3, hi = 5, target = 6;
    Solution s;
    cout << s.solve(lo, hi, target) << endl;


    return 0;
}