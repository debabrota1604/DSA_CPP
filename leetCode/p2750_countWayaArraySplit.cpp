class Solution {
    const int modVal = 1000000007;
public:
    int factorial(int n){
        int memo[2] = {1,1};
        for(int i=1; i<=n; i++){
            memo[i&1] = memo[(i-1)&1] * i;
        }
        cout << "factorial of " << n << " is " << memo[n&1] << endl;
        return memo[n&1]%modVal;
    }
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        unsigned long long res=0;
        vector<int> indices;
        for(int i=0; i<nums.size();i++){
            if(nums[i] == 1){
                indices.emplace_back(i);              
            }
        }
        if(!indices.empty()){
            res=1;
            for(int i=0; i<indices.size()-1;i++){
                int diff = indices[i+1] - indices[i];
                if(diff >1){
                    res *= diff;
                    res > modVal ? res%=modVal:1;
                }
            }
        }        
        return (int)res;
        
    }
};
