#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumTripletValue(vector<int> nums) {
        long long res=LONG_MIN;
        for(int iter=0; iter<nums.size()-2; iter++){
            for(int iter2=iter+1; iter2<nums.size()-1; iter2++){
                if(res >0 && (nums[iter]-nums[iter2])<0) continue;
                for(int iter3=iter2+1; iter2<nums.size(); iter3++){
                    long long val = (nums[iter]-nums[iter2]);
                    val*= (long long) nums[iter3];
                    if(val > res) res = val;
                }
            }
        }
        return  res<0?0:res;
    }
};




int main(){
    Solution s;

    cout << s.maximumTripletValue([12,6,1,2,7]) << endl;

    return 0;
}