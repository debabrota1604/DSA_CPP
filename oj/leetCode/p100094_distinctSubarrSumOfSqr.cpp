#include<bits/stdc++.h>
using namespace std;

/*
You are given a 0-indexed integer array nums.

The distinct count of a subarray of nums is defined as:

Let nums[i..j] be a subarray of nums consisting of all the indices from i to j such that 0 <= i <= j < nums.length. Then the number of distinct values in nums[i..j] is called the distinct count of nums[i..j].
Return the sum of the squares of distinct counts of all subarrays of nums.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,2,1]
Output: 15
Explanation: Six possible subarrays are:
[1]: 1 distinct value
[2]: 1 distinct value
[1]: 1 distinct value
[1,2]: 2 distinct values
[2,1]: 2 distinct values
[1,2,1]: 2 distinct values
The sum of the squares of the distinct counts in all subarrays is equal to 12 + 12 + 12 + 22 + 22 + 22 = 15.
Example 2:

Input: nums = [1,1]
Output: 3
Explanation: Three possible subarrays are:
[1]: 1 distinct value
[1]: 1 distinct value
[1,1]: 1 distinct value
The sum of the squares of the distinct counts in all subarrays is equal to 12 + 12 + 12 = 3.
 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100
*/


class Solution {
public:
    // converts vector of integers to string of integers
    string vecToStr(vector<int> inp){
        sort(inp.begin(), inp.end());
        string res="";
        for(int iter=0; iter<inp.size(); iter++){
            res += inp[iter] + '0';
        }
        return res;
    }

    // computes all subarrays from the input array
    void subarrSet(vector<int>& inp, vector<string>& res){

        for(int iter=0; iter<inp.size(); iter++){
            for(int iter2=iter; iter2 <= inp.size(); iter2++){
                cout << iter << ":" << iter2 << endl;
                vector<int> temp(inp.begin()+iter, inp.begin()+iter2+1);
                res.emplace_back(vecToStr(temp));
            }
        }
    }
    int sumCounts(vector<int>& nums) {

        // Step1: Compute subarrays
        vector<string> res;
        subarrSet(nums, res);


        // Step2: Insert them into map to get unique elements with frequency.
        unordered_map<string, int> mp;
        for(int iter=0; iter<res.size(); iter++){
            cout << iter << ":= " << res[iter] << endl; 
            mp[res[iter]]++;
        }

        // Step3: Count each frequency with sum of squares
        int result = 0;
        for(auto iter:mp){
            result += iter.second * iter.second;
            //cout << iter.second << endl;
        }

        cout << "Returning: " << endl;
        return result;
    }
};


int main(){
    vector<int> inp {1,2,1};
    Solution s;
    cout << "Result: " << s.sumCounts(inp) << endl; 
}

/*
Progress:

Not able to run successfully! Currently not giving correct count.
*/