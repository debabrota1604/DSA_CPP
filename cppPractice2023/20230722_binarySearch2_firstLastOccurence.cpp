#include<bits/stdc++.h>
using namespace std;


// This functions can be used to find the number of occurences 
// of a number in a sorted array in log(n) time.

int firstOccurence(vector<int>& inp, int key){
    int lo = 0, hi = inp.size() -1, ans =-1;
    
    while(lo <= hi){
        int mid = lo + (hi - lo)/2;

        if(inp[mid] == key){
            ans = mid;
            hi = mid-1; // Loop again to check same key in earlier indices
        }

        if(key > inp[mid]) lo = mid+1;
        if(key < inp[mid]) hi = mid-1;
    }
    return ans;
}

int lastOccurence(vector<int>& inp, int key){
    int lo = 0, hi = inp.size() -1, ans =-1;
    
    while(lo <= hi){
        int mid = lo + (hi - lo)/2;

        if(inp[mid] == key){
            ans = mid;
            lo = mid +1; //Loop again to check key in next indices
        }

        if(key > inp[mid]) lo = mid+1;
        if(key < inp[mid]) hi = mid-1;
    }
    return ans;
}


int main(){

    vector<int> v1 { 2, 4, 6, 6, 6, 6, 6, 6, 11, 24, 30};

    cout << "First Occurence of 6: " << firstOccurence(v1, 6) << endl;
    cout << "Last Occurence of 6: " << lastOccurence(v1, 6) << endl;

    cout << "First Occurence of 10: " << firstOccurence(v1, 10) << endl;
    cout << "Last Occurence of 10: " << lastOccurence(v1, 10) << endl;

    cout << "First Occurence of 11: " << firstOccurence(v1, 11) << endl;
    cout << "Last Occurence of 11: " << lastOccurence(v1, 11) << endl;

    return 0;
}