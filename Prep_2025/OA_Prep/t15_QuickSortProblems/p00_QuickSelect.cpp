//https://www.geeksforgeeks.org/quickselect-algorithm/

#include <bits/stdc++.h>
using namespace std;

// Standard partition process of QuickSort. Considers the last element as pivot
// moves smaller elements to left and greater elements to the right.
int partition(vector<int>& arr, int l, int r) {
    int pivot = arr[r], start = l; 
    for (int current = l; current <= r - 1; current++) { 
        if (arr[current] <= pivot) {
            swap(arr[start], arr[current]);
            start++;
        }
    }
    swap(arr[start], arr[r]);
    return start;
}

// ASSUMPTION: ALL ELEMENTS IN ARR[] ARE DISTINCT.
int kthSmallest(vector<int>& arr, int l, int r, int k) {
  
    if (k > 0 && k <= r - l + 1) { // If k is smaller than the number of elements in array

        // Partition array with last element and get the pivot element pos in the sorted array.
        int index = partition(arr, l, r);

        if (index - l == k - 1)
            return arr[index]; //position is the same as k.

        
        if (index - l > k - 1) // Position is higher, recur for the left subarray.
            return kthSmallest(arr, l, index - 1, k);

        
        return kthSmallest(arr, index + 1, r, k - index + l - 1); // Recur for the right subarray.
    }

    return INT_MAX; // If k is more than the number of elements in the array.
}

int main() {
    vector<int> arr = {10, 4, 5, 8, 6, 11, 26};
    int n = arr.size();
    int k = 3;
    cout << k << "-th smallest element is " << kthSmallest(arr, 0, n - 1, k) << endl;
    return 0;
}