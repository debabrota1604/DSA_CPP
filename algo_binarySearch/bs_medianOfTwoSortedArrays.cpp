#include<bits/stdc++.h>
using namespace std;


/*
Given two sorted arrays a1 and a2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 
Example 1:
    Input: a1 = [1,3], a2 = [2]
    Output: 2.00000
    Explanation: merged array = [1,2,3] and median is 2.

Example 2:
    Input: a1 = [1,2], a2 = [3,4]
    Output: 2.50000
    Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 
Constraints:
    a1.length == m
    a2.length == n
    0 <= m <= 1000
    0 <= n <= 1000
    1 <= m + n <= 2000
    -106 <= a1[i], a2[i] <= 106
*/

/*
Key points:
    1. We want to make two cuts, separating a1 into [. . . . l1 | r1 . . . ] and a2 into [. . . . l2 | r2 . . . ] respectively, so that [. . . . l1] + [. . . . l2] has equal number of elements as [r1 . . . ] + [r2 . . . ]. Our goal is to find such cutting positions that give us the median values.
    2. For an array of length N, there are 2*N + 1 different cutting positions.
    3. Cutting on a gap is simple. Cutting on a number means both left half and right half get the number.
    4. With two arrays, a valid cutting position that gives the median can be ANY cutting position of the shorter array. This is not true for the longer array. Therefore, we always cut the shorter array, and then calculate the cutting position of longer array directly(by using the fact that each half has the same number of cutting positions). We want to make a1 always point to the shorter array for convenience.
    5. Using binary search, If l1 > r2, we know current cutting position is incorrect. A valid cutting position for median should be on the left half of a1.
    6. If l2 > r1, we know current cutting position is incorrect. A valid cutting position for median should be on the right half of a1.
    7. if l1 < r2 and l2 < r1, we are good. median = (max(l1, l2) + min(r1, r2)) / 2
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& a1, vector<int>& a2) {
        // Make sure a1 is shorter
        if(a1.size() > a2.size()) return findMedianSortedArrays(a2, a1);

        int n1 = a1.size(), n2 = a2.size();

        // range of a1 cut location: n1 means no right half for a1
        int lo = 0, hi = n1;
        while(lo <= hi){

            // Step1: determine cut indices
            int cut1 = lo + (hi-lo)/2;
            int cut2 = (n1+n2)/2 - cut1;

            // Step2: determine the endpoints for two cut indices.
            double l1 = (cut1 == 0) ? INT_MIN : a1[(cut1 -1)];
            double l2 = (cut2 == 0) ? INT_MIN : a2[(cut2 -1)];
            double r1 = (cut1 == n1) ? INT_MAX : a1[cut1];
            double r2 = (cut2 == n2) ? INT_MAX : a2[cut2];

            // Step3: Change variables for next loop in binary search
            if(l1>r2) hi = cut1 - 1;	// A1's lower half is too big; need to move C1 left (C2 right)
            else if(l2>r1) lo = cut1 + 1;	// A2's lower half too big; need to move C2 left.
            else return (n1+n2)&1 ? min(r1,r2) : (max(l1,l2) + min(r1, r2))/2;	// Otherwise, that's the right cut.
        }
        return -1; //never comes here
    }
};


int main(){

    Solution s;

    vector<int> v1 {}, v2 {2,3};
    cout << s.findMedianSortedArrays(v1,v2) << endl;
}