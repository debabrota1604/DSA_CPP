#include<iostream>
#include<vector>
using namespace std;


int binarySearchIterative(vector<int>& arr, int key){
    int keyIndex, lo, hi, mid;
    lo=0;
    hi=arr.size();
    keyIndex = -1;


    while (lo<hi)
    {
        mid = lo + (hi-lo)/2;

        if(arr[mid] ==key) return mid;

        if(arr[mid] <key){
            //key is on the right half
            lo = mid+1;
        }
        else{
            hi = mid-1;
        }
    }
    return keyIndex;
    
}


int recursive_search(vector<int>& arr, int key, int lo, int hi){
    // Error Case
    if(lo > hi) return -1;

    int mid = lo + (hi-lo)/2;
    if(key == arr[mid]) return mid;
    else if(key < arr[mid]){
        // Key can be present in the left half
        return recursive_search(arr, key, lo, mid-1);
    }
    else{
        // Key can be present in the right half
        return recursive_search(arr, key, mid+1, hi);
    }
}

int binarySearchRecursive(vector<int>& arr, int key){
    return recursive_search(arr, key, 0, arr.size()-1);
}
int main(){

    vector<int> sortedArr {1,3,5,6,7,8,9,11,15};
    int key = 11;
    cout << "Iterative Binary search for key " << key << " is found at index " << binarySearchIterative(sortedArr, key) << endl;

    cout << "Recursive Binary search for key " << key << " is found at index " << binarySearchIterative(sortedArr, key) << endl;


    return 0;
}