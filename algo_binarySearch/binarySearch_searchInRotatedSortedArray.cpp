#include<iostream>
#include<vector>
using namespace std;

int getPivot(vector<int> arr){
    int lo, hi, mid;
    lo=0;
    hi = arr.size()-1;

    while(lo < hi){
        mid = lo + (hi -lo)/2;

        if(arr[mid] >= arr[0]) lo = mid +1;
        else hi = mid;
    }
    return lo;
}

int binarySearch(vector<int> arr, int lo, int hi, int key){
    int mid;
    while(lo <=hi){
        mid = lo + (hi-lo)/2;
        if(arr[mid] == key) return mid;
        else if(key > arr[mid]) lo = mid+1;
        else hi = mid-1;
    }
    return -1;
}

int find_key(vector<int> arr, int key){
	int pivot = getPivot(arr);
	if( key >= arr[pivot] && key <= arr[arr.size()-1]) //Key exists in the lower half
		return binarySearch(arr, pivot, arr.size()-1, key);
	else if (key >= arr[0] && key <= arr[pivot-1]) // Key exists in the higher sorted half
		return binarySearch(arr, 0, pivot-1, key);
    else return -1; //element is out of array bounds
}


int main(){
    vector<int> vec {7,9,1,2,3};
    int key = 2;
    cout << "Key " << key << " exists in array index: " << find_key(vec, key) << endl;

    return 0;
}