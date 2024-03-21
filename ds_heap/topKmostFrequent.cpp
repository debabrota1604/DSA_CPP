#include<bits/stdc++.h>
using namespace std;

/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Example 1:
    Input: nums = [1,1,1,2,2,3], k = 2
    Output: [1,2]

Example 2:
    Input: nums = [1], k = 1
    Output: [1]
 
Constraints:
    1 <= nums.length <= 105
    -104 <= nums[i] <= 104
    k is in the range [1, the number of unique elements in the array].
    It is guaranteed that the answer is unique.
*/

using map_iter = unordered_map<int,size_t>::iterator;

struct Compare{
    bool operator()(map_iter a, map_iter b) const { return a->second > b->second; }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step1: Count freq counter
        unordered_map<int,size_t> ump;
        for(auto item:nums) ++ump[item];

        // add frequencies and elements to the heap to get sorted order
        priority_queue<map_iter, vector<map_iter>, Compare> pq;
        for(auto iter = ump.begin(); iter!=ump.end(); ++iter){
            pq.push(iter);
            if(pq.size() >k) pq.pop();
        }

        // Construct the result vector
        vector<int> res;
        //must loop on k, iterating over pq.size() will give less results as size is changing
        for(int iter=0;iter<k; iter++){ 
            res.emplace_back(pq.top()->first);
            pq.pop();
        }
        //cout << ump.size() << ":" << pq.size() << ":" << res.size() << endl;
        return res;
    }
};


int main(){
    Solution s;
    vector<int> num {1,1,1,2,2,3}, num2 {1};
    int k {2}, k2{1};

    for(auto item: s.topKFrequent(num, k) ) cout << item << " ";
    cout << endl;
    for(auto item: s.topKFrequent(num2, k2) ) cout << item << " ";
    cout << endl;


    return 0;
}