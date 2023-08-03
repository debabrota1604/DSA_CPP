
// C++ program to print largest contiguous array sum : Kedene's Algorithm
#include <bits/stdc++.h>
using namespace std;
 
int maxSubArraySum(int a[], int size)
{
    int finalMax = INT_MIN, tempMax = 0;
 
    for (int i = 0; i < size; i++) {
        tempMax = tempMax + a[i];
        if (finalMax < tempMax)
            finalMax = tempMax;
 
        if (tempMax < 0)
            tempMax = 0;
    }
    return finalMax;
}
 
// Driver Code
int main()
{
    int a[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
    int n = sizeof(a) / sizeof(a[0]);
 
    // Function Call
    int max_sum = maxSubArraySum(a, n);
    cout << "Maximum contiguous sum is " << max_sum;
    return 0;
}