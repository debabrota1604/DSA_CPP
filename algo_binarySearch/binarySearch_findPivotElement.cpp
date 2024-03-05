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

int main(){
    vector<int> vec {7,9,1,2,3};
    cout << "Peak element in the array: " << getPivot(vec) << endl;
    return 0;
}