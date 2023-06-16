#include<bits/stdc++.h>
using namespace std;

// Problem:Given an array of n integers. Each array element is obtained by adding 
// either +1 or -1 to previous element i.e absolute difference between any two 
// consecutive elements is 1. The task is to search an element index with the 
// minimum number of comparison (less than simple element by element search). 
// If the element is present multiple time, then print the smallest index. 
// If the element is not present print -1.

// Algorithm: Given the property of each element being related to its previous 
// element by +1 or -1, we can calculate the next index by using the distance between 
// the key and present index value. We cannot use binary search as the array is not 
// sorted and search may need to be done on both sides.
// the distance between index value and key by computing abs(arr[ind] - key).

int efficientSearch(vector<int> &arr, int key){
    int index = 0;
    cout << "Starting at index 0: \t" << arr[index] << endl;

    while(index <arr.size()){
        if(arr[index] == key)
            return index;
        else{
            index += abs(arr[index] - key); 
            cout << "Jumping to index " <<index << ": \t" << arr[index] << endl;
        }
    }
    return -1;
}

int main(){
    vector<int> vec {-5,-6,-5,-4,-3,-4,-3,-2,-1,0,-1,-2,-1,-2,-1,0,1,2,1,2,3,4,5,4,3,4,5,6,5,6,7,8,9,8,7,6,5,4}, vec2{1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,0,-1};
    int searchKey = -1;
    cout << efficientSearch(vec2,searchKey) << " is the lowest index where " << searchKey << " is found!" << endl;


    return 0;
}