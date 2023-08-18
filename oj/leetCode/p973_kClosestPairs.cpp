#include<bits/stdc++.h>
using namespace std;

/*
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).
The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).
You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

 

Example 1:
Input: points = [[1,3],[-2,2]], k = 1
Output: [[-2,2]]
Explanation:
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].

Example 2:
Input: points = [[3,3],[5,-1],[-2,4]], k = 2
Output: [[3,3],[-2,4]]
Explanation: The answer [[-2,4],[3,3]] would also be accepted.

*/


class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> result(k);
        
        // Step1: Use maxHeap to track smallest k elements.
        // Two ways to think:
        // 1. Use minHeap. Insert all n elements. Pop first k elements
        // 2. Use maxHeap. Insert all n elements with the condition of max size k. 
        //    Once size greater than k, delete the root, that is the max of all remaining.
        //    After all n insertions, we are left with k smallest elements in the array.
        priority_queue<vector<int>> maxHeap;
        
        //Construct maxheap with max k elements
        for (auto& p : points) {
            int x = p[0], y = p[1];           
            
            maxHeap.push({x*x + y*y, x, y});
            if (maxHeap.size() > k) {
                //Skipped when less than k elements are inserted
                maxHeap.pop();
            }
        }
        
        // Step 2: Copy the k smallest elements from the heap to result
        for (int i = 0; i < k; ++i) {
            vector<int> top = maxHeap.top();
            maxHeap.pop();
            result[i] = {top[1], top[2]};
        }
        
        return result;
    }
};