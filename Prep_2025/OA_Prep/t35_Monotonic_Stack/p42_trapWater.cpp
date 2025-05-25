#include<bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/trapping-rain-water/
 
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Example 1:
    Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
    Output: 6
    Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

Example 2:
    Input: height = [4,2,0,3,2,5]
    Output: 9
    
Constraints:
    n == height.length
    1 <= n <= 2 * 104
    0 <= height[i] <= 105

 */

// Monotonic Stack stores indices of the bars in a way that the heights are in increasing order.
// Loop iterates through the heights, and for each height, it checks if the current height is greater than the height at the index stored at the top of the stack.
// If it is, it means we can trap water. The trapped water is calculated based on the distance between the current index and the index at the top of the stack, and the height difference between the current height and the height at the index popped from the stack.
int trap_MonotonicStack(const vector<int>& height) {
    int n = height.size();
    stack<int> st;
    int waterTrapped = 0;

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && height[i] > height[st.top()]) {
            int topIndex = st.top();
            st.pop();
            if (st.empty()) break;
            int distance = i - st.top() - 1;
            int boundedHeight = min(height[i], height[st.top()]) - height[topIndex];
            waterTrapped += distance * boundedHeight;
        }
        st.push(i);
    }

    return waterTrapped;
}

int trap_noSpace(const vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;
    
    int left = 0, right = n - 1;
    int maxLeft = 0, maxRight = 0;
    int waterTrapped = 0;

    while (left <= right) {
        if (height[left] <= height[right]) {
            if (height[left] > maxLeft) {
                maxLeft = height[left];
            } else {
                waterTrapped += maxLeft - height[left];
            }
            left++;
        } else {
            if (height[right] > maxRight) {
                maxRight = height[right];
            } else {
                waterTrapped += maxRight - height[right];
            }
            right--;
        }
    }

    return waterTrapped;
}