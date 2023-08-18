#include<bits/stdc++.h>
using namespace std;

int gcd2(int x, int y){
    if(x==0) return y;
    else return gcd2(y%x,x);
}


int gcdN(vector<int> nums, int si, int ei, int k){
    int res = nums[si], count=0;
    for(int it=si+1; it<ei; it++){
        res = gcd2(res, nums[it]);
        if(res==k) count++;
    }
    return count;
}

class Solution {
public:
    int gcd2(int x, int y){
        if(x==0) return y;
        else return gcd2(y%x,x);
    }


    bool gcdN(vector<int> nums, int si, int ei, int k){
        cout << "gcdN: " << si << " " << ei << endl;
        int res = nums[si];
        for(int it=si+1; it<ei; it++){
            cout << "\t" << it << ": GCD of " << res << " & " << nums[it] << ": ";
            res = gcd2(res, nums[it]);
            cout << res << endl;
        }
        if(res!=k) return false;
        cout << "True for subarray: " << si << " " << ei-1 << endl; return true;
    }
    int subarrayGCD(vector<int>& nums, int k) {
        int count=0;
        for(int i1=0; i1<nums.size(); i1++){
            for(int i2=i1; i2<=nums.size(); i2++){
                if(gcdN(nums,i1, i2,k)){ count++;}
            }
        }
        return count;
    }
};



int main(){
    vector<int> nums={9,3,1,2,6,3}; int k=3;
    Solution s;
    cout << "GCD2: " << s.gcd2(9,3) << endl;
    cout << s.subarrayGCD(nums,k) << endl;




    return 0;
}