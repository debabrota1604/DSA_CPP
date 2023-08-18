#include<bits/stdc++.h>
using namespace std;

// Problem
// Given two sorted arrays of size m and n respectively, you are tasked with 
// finding the element that would be at the k’th position of the final sorted array.

// Input : Array1 [2 3 6 7 9],  Array2 [1 4 8 10], k = 5
// Output: 6

// Solution:
//     1. As the arrays are sorted, we can use the binary search to find an element in order.
//     2. Need to modify the search condition to generate subproblems as kth element is 
//     needed rather than finding a search key.
//     3. calculate mid for both arrays. If sum of two mid is greater than k, that means the 
//     kth element is somewhere lessar than mid for one of the arrays. Compare arr[mid1] & arr[mid2]
//     and replace the larger one as hi for the next subproblem.
//     4. If sum of two mid is less than k, then we need to increase the lo to mid value 
//     for one of the arrays. compare arr[mid1] & arr[mid2] and whichever is higher, replace with hi.

int kth(vector<int> v1, vector<int> v2, int lo1, int lo2, int hi1, int hi2, int k){
    //calculate mid for both arrays
    int mid1 = lo1 +(hi1 - lo1)/2, mid2 = lo2+ (hi2-lo2)/2;
    cout << lo1 << " " << hi1 << " " << lo2 << " " << hi2 << endl; getchar();

    if (lo1==hi1) return v1[k];
    if (lo2==hi2) return v2[k];

    if(mid1+mid2 <k){ //kth member exists to the right of both mid
        if(v1[mid1] > v2[mid2])
            return kth(v1, v2, lo1, mid2+1, hi1, hi2, k-mid2-1);
        else return kth(v1, v2, mid1+1, lo2, hi1, hi2, k-mid1-1);
    }
    else{ //kth number exists in the left of both the arrays
        if(v1[mid1] > v2[mid2])
            return kth(v1, v2, lo1, lo2, lo1+mid1, hi2, k);
        else return kth(v1, v2, lo1, lo2, hi1, lo2+mid2, k);
    }

}


int main(){
    vector<int> v1, v2; v1 = { 12,13,16,17,19};  v2 = {11,14,15,18,20};
    int k = 2;
    v1 = {11, 13, 15, 17, 19}, v2 = {10, 12, 14, 16, 18};
    for(int i =0; i<v1.size(); i++){
        cout << v1[i] <<  " " << v2[i] <<endl;
    }

    for (int i=0; i< 10; i++){
        cout << i << ": " << kth(v1,v2, 0,0, v1.size(),v2.size(), i) << endl;
    }



    return 0;
}