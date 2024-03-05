#include<iostream>
#include<vector>
using namespace std;

int first_occurance(vector<int>& arr, int key){
    int lo, hi, mid, ans=-1;
    lo =0;
    hi = arr.size()-1;
    while(lo <= hi){
        mid  = lo + (hi-lo)/2;
        if(arr[mid] == key){
            ans = mid;
            hi = mid-1;
        }
        else if(key > arr[mid]) lo = mid +1;
        else hi = mid -1;
    }
    return ans;
}
int last_occurance(vector<int>& arr, int key){
    int lo, hi, mid, ans=-1;
    lo =0;
    hi = arr.size()-1;
    while(lo <= hi){
        mid  = lo + (hi-lo)/2;
        if(arr[mid] == key){
            ans = mid;
            lo = mid+1;
        }
        else if(key > arr[mid]) lo = mid +1;
        else hi = mid -1;
    }
    return ans;
}

int main(){
    vector<int> arr {0, 1, 1, 2, 2, 2, 2, 3, 3, 3, 4};
    int key = 2;

    cout << "First Occurance of key " << key << ": " << first_occurance(arr, key) +1 << endl;
    cout << "Last Occurance of key " << key << ": " << last_occurance(arr, key) +1 << endl;


    return 0; 
}