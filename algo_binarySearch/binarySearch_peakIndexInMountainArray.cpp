#include<iostream>
#include<vector>
using namespace std;


// Dummy search code for comparison
int binarySearch(vector<int> arr, int key){
    int lo, hi, mid;
    lo=0;
    hi = arr.size()-1;
    while(lo <=hi){
        mid = lo + (hi-lo)/2;
        if(arr[mid] == key) return mid;
        else if(key > arr[mid]) lo = mid+1;
        else hi = mid-1;
    }
    return -1;
}

int getPeak(vector<int> arr){
    int lo, hi, mid;
    lo =0;
    hi = arr.size()-1;
    while(lo <= hi){
        mid  = lo + (hi-lo)/2;
        if(arr[mid] > arr[mid -1] && arr[mid] > arr[mid +1]) return mid;
        else if(arr[mid] > arr[mid -1]) lo = mid;
        else hi = mid;
    }
    return -1;
}


int main(){
    vector<int> vec { 0,1,2,0};
    vector<int> vec2 { 0,1,2,3,4,3,2,1,0,-1};
    cout << "Peak in Mountain array: " << getPeak(vec2) << endl;


    return 0;
}