#include<bits/stdc++.h>
using namespace std; 
 
#define LL long long
#define LD long double
#define CY cout<<"YES\n"
#define cCNn cout<<"NO\n"
#define PR pair<int,int>
 
// 48-57 -> 0-9
// 65-90 -> A-Z
// 97-122 -> a-z
class Solution {
public:
    bool checkFixBound(vector<int> nums, int lo, int hi, int minK, int maxK){
        int min=INT_MAX,max=INT_MIN;
        for(int it=lo; it<hi; it++){
            if(nums[it] > max) max = nums[it];
            if(nums[it] < min) min = nums[it];
        }
        if(max != maxK || min != minK) return false;
        cout << "Member: " << lo << " " << hi << endl;
        return true;
    }
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long res=0;
        for(int i=0;i<nums.size();){
            for(int j=i+1;j<=nums.size();){
                cout << i << " " << j << endl;
                int min=INT_MAX,max=INT_MIN;
                for(int it=i; it<j; it++){
                    if(nums[it] > max) max = nums[it];
                    if(nums[it] < min) min = nums[it];
                }
                if(max == maxK && min == minK){ cout << "Member: " << i << " " << j << endl; res++; i++; j++;}
                else if(max !=maxK){
                    
                }
                else if(min !=minK){

                }

                if(nums[i] <minK || nums[i] >maxK){ i++; break;}
                if(nums[j] <minK || nums[j] >maxK){ i = j++; break;}
            }
        }
        return res;
    }
};

int main()
{
    Solution s; vector v1 {1,3,5,2,7,5}, v2 {1,1,1,1};

    cout << s.countSubarrays(v1,1,5) << endl;
    cout << s.countSubarrays(v2,1,1) << endl;
       
    return 0;
}
