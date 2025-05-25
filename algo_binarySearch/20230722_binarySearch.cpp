#include<bits/stdc++.h>
using namespace std;


int binarySearch(vector<int>& inp, int key){
    int lo = 0, hi = inp.size() -1;
    
    while(lo <= hi){
        int mid = lo + (hi - lo)/2;
        if(inp[mid] == key) return mid;

        if(key > inp[mid]) lo = mid+1;
        if(key < inp[mid]) hi = mid-1;
    }
    return -1;
}

int main(){

    vector<int> v1 { 2, 4, 6, 11, 24, 30};

    cout << "Found 4: " << binarySearch(v1, 4) << endl;
    cout << "Found 10: " << binarySearch(v1, 10) << endl;
    cout << "Found 30: " << binarySearch(v1, 30) << endl;

    return 0;
}