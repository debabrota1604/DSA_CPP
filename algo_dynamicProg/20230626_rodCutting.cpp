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


    int MaxCutCount(const vector<int>& segs, int RodLen){
        // this version focuses on maximizing the number of pieces
        if(RodLen ==0) return 0;

        int ans = INT_MIN;
        for(int iter=0; iter<segs.size(); iter++){
            if(RodLen - segs[iter] >=0)
                ans = max(ans, MaxCutCount(segs, RodLen - segs[iter]) +1);
        }
        return ans;
    }

    /*
    Step 1: Create a dp array of n+1 size
    Step 2: whatever the current ans returning, first store in the dp array then return it.
    Step 3: Modify the base case to return if the result is already present there.
    */

    // vector<int> dp (n+1, -1);
    int MaxCutCount_memoization(const vector<int>& segs, vector<int>& dp, int RodLen){
        // this version focuses on maximizing the number of pieces
        if(RodLen ==0) return 0;
        if(dp[RodLen] != -1) return dp[RodLen];

        int ans = INT_MIN;
        for(int iter=0; iter<segs.size(); iter++){
            if(RodLen - segs[iter] >=0)
                ans = max(ans, MaxCutCount_memoization(segs, dp, RodLen - segs[iter]) +1);
        }
        dp[RodLen] = ans;
        return ans;
    }

    int maxCut_tabulation(const vector<int>& segs, int RodLen){
        vector<int> dp (RodLen +1, INT_MIN);
        dp[0] =0;
        for(int iter=0; iter<=RodLen; iter++){
            for(int cut=0; cut<segs.size(); cut++){
                if(iter >= segs[cut]) 
                    dp[iter] = max(dp[iter], dp[iter - segs[cut]] +1);
            }
        }
        return dp.back() < 0? 0 : dp.back();
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