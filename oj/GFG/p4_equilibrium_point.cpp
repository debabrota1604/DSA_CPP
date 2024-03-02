//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

//Given an array A of n non negative numbers. The task is to find the first equilibrium point in an array. Equilibrium point in an array is an index (or position) such that the sum of all elements before that index is same as sum of elements after it.

//Note: Return equilibrium point in 1-based indexing. Return -1 if no such point exists. 


class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
        // Your code here
        int lo=0, hi=0;
        if(n ==1) return 1;
        for(int iter=1; iter<n; iter++) hi += a[iter];
        
        for(int iter=1; iter<n; iter++){
            if(lo == hi) return iter;
            lo +=a[iter-1];
            hi -=a[iter];
        }
        return -1;
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends