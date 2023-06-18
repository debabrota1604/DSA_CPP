class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int diff=INT_MAX;
        for(int i=1; i<nums.size(); i++){
            int localDiff = abs(nums[i-1] - nums[i]);
            if(localDiff < diff) diff = localDiff;
        }
        return diff;        
    }
};
