#include<bits/stdc++.h>
using namespace std;


int binarySearch(vector<int> inp, int key){
    int mid, lo, hi;
    lo = 0;
    hi = inp.size()-1;
    while(lo<=hi){
        mid = lo + (hi-lo)/2;
        //cout << lo << " " << hi <<  " " << mid << endl;

        if(key < inp[mid]) hi = mid -1;
        else if(key >inp[mid]) lo = mid+1;
        else return mid;
    }
    return -1;
}

// Recursive & overloaded
int binarySearch(vector<int> inp, int key, int lo, int hi){
    int mid = lo + (hi-lo)/2;
    if(lo > hi) return -1;
    else if(key < inp[mid]) return binarySearch(inp, key, lo, mid-1);
    else if(key > inp[mid]) return binarySearch(inp, key, mid+1, hi);
    else return mid;
}


int firstOccurence(vector<int> inp, int key){
    int lo=0, hi = inp.size()-1, mid, res=-1;
    while(lo <= hi){
        mid = lo + (hi-lo)/2;
        if(key == inp[mid]){
            res = mid;
            hi = mid-1; // Search again for the previous key in the array
        }
        else if(key < inp[mid]) hi = mid -1;
        else lo = mid +1;
    }
    return res;
}
int lastOccurence(vector<int> inp, int key){
    int lo=0, hi = inp.size()-1, mid, res=-1;
    while(lo <= hi){
        mid = lo + (hi-lo)/2;
        if(key == inp[mid]){
            res = mid;
            lo = mid+1; //Search again for the next key in the array
        }
        else if(key < inp[mid]) hi = mid -1;
        else lo = mid +1;
    }
    return res;
}

/*
Iterator lower_bound (Iterator first, Iterator last, const val)  
lower_bound returns an iterator pointing to the first element in the range [first,last)
which has a value not less than ‘val’  and if the value is not present in the vector then it returns the end iterator.

Iterator upper_bound (Iterator first, Iterator last, const val)
upper_bound returns an iterator pointing to the first element in the range [first,last) 
which has a value greater than ‘val’  and if the value is not present in the vector then it returns the end iterator.
*/

int lowerBound(vector<int> inp, int key){
    int lo=0, hi = inp.size()-1, mid, res=-1;
    while(lo <= hi){
        mid = lo + (hi-lo)/2;
        if(key <= inp[mid]){
            res = mid;
            hi = mid -1; //Search again for the next key in the array
        }
        else if(key < inp[mid]) hi = mid -1;
        else lo = mid +1;
    }
    return res;

}

int main(){
    vector<int> inp {1, 4, 7, 8, 10, 15};
    int key = 15;
    cout << "Binary Search Iterative: " << binarySearch (inp, key) << endl;
    cout << "Binary Search Recursive: " << binarySearch (inp, key, 0, inp.size()-1) << endl;

    vector<int> firstLast {1,1,1,1,2,3,4,4,4,4,4,5,6,6,6,6,7};
    int key2 = 0;
    cout << "First Occurence for " << key2 << ": " << firstOccurence(firstLast, key2) << endl;
    cout << "Last Occurence for " << key2 << ": " << lastOccurence(firstLast, key2) << endl;



    return 0;
}