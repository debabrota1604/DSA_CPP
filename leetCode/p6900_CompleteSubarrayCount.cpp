#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int> uniq (nums.begin(), nums.end());
        int res =0, uSize = uniq.size(), flag=1;

        auto lo = nums.begin(), hi = nums.begin();
        advance(hi, uSize-1);

        while(1){
            set<int> temp (lo, hi);
            if(temp.size() == uSize){
                res++;
                if(flag){
                    hi++;
                }
                else{
                    lo++;
                }
                !flag;
            }
            else
        }
        
        for(auto iter=nums.begin(); iter!=nums.end();){
            
            //advance(iter2, uSize);
            for(auto iter2 = iter; iter2 !=nums.end(); iter2++){
                cout << "Inside" << endl;
                set<int> temp (iter, iter2);
                
                if(temp.size() == uSize){
                    iter++;
                    res++;
                }
            }
            iter++;
        }
        return res;
    }
};


int main(){
    Solution s;
    vector<int> v {1,3,1,2,2};
    cout << s.countCompleteSubarrays(v) << endl;
}