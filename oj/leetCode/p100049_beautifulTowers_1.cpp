#include<bits/stdc++.h>
using namespace std;

/*
You are given a 0-indexed array maxHeights of n integers.

You are tasked with building n towers in the coordinate line. The ith tower is built at coordinate i and has a height of heights[i].

A configuration of towers is beautiful if the following conditions hold:

1 <= heights[i] <= maxHeights[i]
heights is a mountain array.
Array heights is a mountain if there exists an index i such that:

For all 0 < j <= i, heights[j - 1] <= heights[j]
For all i <= k < n - 1, heights[k + 1] <= heights[k]
Return the maximum possible sum of heights of a beautiful configuration of towers.

*/
//Code was acceopted. But same problem was given in BeautifulTower-2 with higher array size. That needs DP probably.

class Solution {
public:

    // Computes the maximum height mountain possible with peak at given index
    long long getMaxHeightAtPeak(int index, vector<int>& maxHeights){
        long long res= maxHeights[index];
        int tempIndex, maxLeft, maxRight;
        maxLeft = maxRight = res;

        // Compute the maximum heights for left of peak
        tempIndex=index-1;
        while(tempIndex >=0){
            maxLeft = min(maxHeights[tempIndex], maxLeft);
            res += maxLeft;
            tempIndex--;
        }

        // Compute the maximum heights for right of peak
        tempIndex=index+1;
        while(tempIndex < maxHeights.size()){
            maxRight = min(maxHeights[tempIndex], maxRight);
            res += maxRight;
            tempIndex++;
        }
        return res;
    }
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        
        long long maxRes=0, res=0, maxEl=maxHeights[0];
        int lastMax=-1;

        //for each occurence of max element, recompute the maxSum
        for(int index=0; index<maxHeights.size(); index++){
            if(index >0 && maxHeights[index] == lastMax){
                lastMax = maxHeights[index];
                continue;
            }
            lastMax = maxHeights[index];
            res = getMaxHeightAtPeak(index, maxHeights);
            if(res >maxRes) maxRes = res;
        }
        return maxRes;
    }
};
