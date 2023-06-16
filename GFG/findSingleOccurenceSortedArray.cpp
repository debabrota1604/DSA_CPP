#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &arr, int num, int lo,int hi){ //index hi is excluded from calculation
    cout << "\tCall Stack: Searching between index " << lo << " to " << hi << endl;
    if (lo >= hi) return -1;

    int midIndex = (hi+lo)/2;
    if (arr[midIndex] == num) return midIndex;
    else if (num < arr[midIndex]) return binarySearch(arr, num, lo, midIndex);
    else return binarySearch(arr, num, midIndex+1, hi); 
}

int findSingleElement(vector<int> &arr, int lo, int hi){
    if (hi == lo) 
        return arr[hi];

    int mid = (hi + lo)/2;  //conditions will be opposite depending upon mid is odd or even

    if (mid%2 == 0){ // mid = 2,4,6

        if (arr[mid] == arr[mid-1]) //if a[6]=a[5]... a[2] = a[1], then key is in left subarray
            return findSingleElement(arr, lo, mid);

        else //if a[6]=a[7] ... a[1] = a[2], then key is in right subarray
            return findSingleElement(arr, mid+2, hi);
    }
    else{
        if (arr[mid] == arr[mid-1]) // a[3] = a[2], a[1] = a[0]... key is in right subarray
            return findSingleElement(arr, mid+1, hi);

        else  // a[3] = a[4], a[1] = a[2].. key is in left
            return findSingleElement(arr, lo, mid-1);
    }   
    
}


int main(){
    //vector<int> v {1,2,3,4,5,6,7,8,9,10,11,12,13,14}; int searchVal = 11;    
    // cout << binarySearch(v, searchVal, 0, v.size()) << " is the index where " << searchVal << " is present." << endl;

    vector<int> rep { 1,1,3,3,4,4,6,6,7,7,8,8,9,11,11};
    cout << "Single element in array is: " << findSingleElement(rep, 0, rep.size()) << endl;





    return 0;
}