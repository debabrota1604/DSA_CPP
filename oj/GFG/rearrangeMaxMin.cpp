#include<bits/stdc++.h>
using namespace std;

// Problem: Given a sorted array of positive integers, rearrange the array 
// alternately i.e first element should be maximum value, second minimum value, 
// third second max, fourth second min and so on. 
// Input: arr[] = {1, 2, 3, 4, 5, 6, 7}
// Output: arr[] = {7, 1, 6, 2, 5, 3, 4}

void display(vector<int> arr){
    for(int item:arr) cout << item << " ";
    cout << endl;
}
// Algorithm 1: Use auxilary array to keep elements. Then replace before return.
// Use two pointer technique to replace at single iteration only.
void rearrangeMaxMin(vector<int> &arr){
    vector<int> res; bool flag=false;
    int lo = 0, hi = arr.size()-1;

    while(lo <=hi){
        if(!flag){ res.emplace_back(arr[hi]);flag = !flag; hi--; }
        else    { res.emplace_back(arr[lo]);flag = !flag; lo++;}
    }
    arr= res;
}

// Algorithm 2: Use modular arithmetic to store intermediate results in a single array.
// Optimization: Time complexity unchanged at O(n). Space complexity reduces drastically from O(n) to O(1).

// How does expression “arr[i] += arr[max_index] % max_element * max_element” work ? 
// The purpose of this expression is to store two elements at index arr[i]. arr[max_index] is stored as multiplier 
// and “arr[i]” is stored as remainder. For example in {1 2 3 4 5 6 7 8 9}, max_element is 10 and we store 91 at 
// index 0. With 91, we can get original element as 91%10 and new element as 91/10.

void rearrangeOptimal(vector<int> &arr)
{
	// initialize index of first minimum and first maximum element
	int max_idx = arr.size() - 1, min_idx = 0;

	// compute maximum element from the sorted array
	int max_elem = arr.back() + 1;

	// traverse array elements
	for (int i = 0; i < arr.size(); i++) {
		// at even index : we have to put maximum element
		if (i % 2 == 0) {
			arr[i] += (arr[max_idx] % max_elem) * max_elem;
			max_idx--;
		}

		// at odd index : we have to put minimum element
		else {
			arr[i] += (arr[min_idx] % max_elem) * max_elem;
			min_idx++;
        }
        display(arr); getchar();
	}
  	
	// array elements back to it's original form
	for (int i = 0; i < arr.size(); i++)
		arr[i] = arr[i] / max_elem;
}



int main(){
    vector<int> vec {1,2,3,4,5,6,7,8,9};

    cout << "Before rearrangement: "; display(vec);

    rearrangeMaxMin(vec);
    // rearrangeOptimal(vec);

    cout << "After rearrangement: "; display(vec);



    return 0;
}