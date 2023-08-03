#include<bits/stdc++.h>
using namespace std;


class RodCutting{
    vector<int> sizes;
    vector<int> weights;
    public:
    RodCutting(vector<int> size, vector<int> value){
        this->sizes = size;
        this->weights = value;
    }

    int MaxCutCount(int RodLen){
        // this version focuses on maximizing the number of pieces

        // Solution: call MaxWeightCut with weights as 1 for all sizes

        return 0;
    }

    int MaxWeightCut(int RodLen){
        if(RodLen<0) return 0;
        int res=0;
        for(int iter=0; iter<sizes.size(); iter++){
            if(RodLen-sizes[iter] >= 0){
                res = max(res,MaxWeightCut(RodLen-sizes[iter]) + weights[iter]);
            }
        }
        return res;
    }
};


class RodCuttingIterative{
    vector<int> sizes,weights;

    public:
    RodCuttingIterative(vector<int> sz, vector<int> val){
        this->sizes = sz;
        this->weights = val;
    }

    int MaxWeightCut(int RodLen){
        vector<int> memo(RodLen +1,0);
        for(int tempLen=0; tempLen<=RodLen; tempLen++){
            int maxWeight=0;
            for(int iter2=0; iter2<sizes.size(); iter2++){
                if(tempLen-sizes[iter2]>=0){
                    maxWeight = max(maxWeight, memo[tempLen-sizes[iter2]] + weights[iter2]);
                }
            }
            memo[tempLen] = maxWeight;
        }
        return memo[RodLen];
    }
};



int main(){
    RodCuttingIterative rc({5,2,2},{1,1,1});
    RodCuttingIterative rc2({3,3,3},{1,1,1});

    cout << "Maximum Cuts possible #1: " << rc.MaxWeightCut(7) << endl;
    cout << "Maximum Cuts possible #2: " << rc2.MaxWeightCut(8) << endl;

    return 0;
}