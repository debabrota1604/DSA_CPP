#include<bits/stdc++.h>
using namespace std;

//Problem: Given an array, reverse every sub-array formed by consecutive k elements.
// Algorithm:
// 1. Write a function to swap numbers in a k element subarray given start and end index.
// 2. Run outer loop for n/k times, each time the inner loop swaps the elements pf the k-ength subarray.

void reversekgroup ( vector<int> &arr, int k){

    //swap array elements in k size chunks
    for( int iter = 0; iter< arr.size(); iter+=k ){

        //compute the indices
        int leftIndex = iter, rightIndex;
        if(iter+k <arr.size()) rightIndex = iter+k-1;
        else rightIndex = arr.size()-1;

        //swap the elements
        while(leftIndex < rightIndex){
            int tempVar = arr[rightIndex];
            arr[rightIndex] = arr[leftIndex];
            arr[leftIndex] = tempVar;
            leftIndex++; rightIndex--;
        }
    }

}

int main(){
    vector<int> vec {1,2,3,4,5,6,7,8,9}; int k=3;

    reversekgroup(vec, k);

    for(int iter=0; iter < vec.size(); iter++) cout << vec[iter] << " ";
    cout << endl;



    return 0;
}