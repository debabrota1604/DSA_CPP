/*
Given an m x n integer matrix heightMap representing the height of each unit cell in a 2D elevation map, return the volume of water it can trap after raining.

Example 1:
    Input: heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
    Output: 4
    Explanation: After the rain, water is trapped between the blocks.
    We have two small ponds 1 and 3 units trapped.
    The total volume of water trapped is 4.

Example 2:
    Input: heightMap = [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]]
    Output: 10

Constraints:
    m == heightMap.length
    n == heightMap[i].length
    1 <= m, n <= 200
    0 <= heightMap[i][j] <= 2 * 104

*/

/*
Approach:
1. Use a priority queue (min-heap) to process the boundary cells first. These cells will determine the minimum height from which water can be trapped.
2. Add all boundary cells to the heap and mark them as visited. 
3. For each cell, check its neighbors (up, down, left, right) and calculate the water trapped based on the height of the current cell and the height of the neighbor.

Why 1-D approaches won't work:
1. Prefix and suffix arrays are not sufficient because the water trapped at a cell depends on the heights of its neighbors, not just the heights to the left and right.
2. Monotonic stacks are typically used for 1-D problems and do not handle the 2D nature of this problem effectively.
3. Two pointers would not work because the problem requires checking all four directions (up, down, left, right) for each cell, which is not feasible with just two pointers.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int rows = heightMap.size();
        int cols = heightMap[0].size();
        if(rows ==0 || cols ==0) return 0;

        vector<vector<bool>> visited (rows, vector<bool>(cols, false));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

        // Step 2: Add the boundary cells to the heap
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1) {
                    pq.emplace(heightMap[r][c], r, c);
                    visited[r][c] = true;
                }
            }
        }

        //Step 3: visit neighbour cells in descending order and compute the water trapped

        int dirs[5] {0,1,0,-1,0};
        int res =0;

        while(!pq.empty()){
            auto [h, r, c] = pq.top();
            pq.pop();

            for(int it=0; it<4; it++){
                int nr = r + dirs[it];
                int nc = c + dirs[it +1];

                if(nr <0 || nc <0 || nr >= rows || nc >= cols || visited[nr][nc]) continue;

                res += max(0, h - heightMap[nr][nc]); // Water trapped at this cell is the difference between the current height and the neighbor's height
                pq.emplace(max(h, heightMap[nr][nc]), nr, nc); // Modify neighbour's height to be the maximum of the current height and neighbor's height
                visited[nr][nc] = true;
            }
        }
        return res;
    }
};