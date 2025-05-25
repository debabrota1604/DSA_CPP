/*
A monotonic stack is a special data structure used in algorithmic problem-solving. 
Monotonic Stack maintaining elements in either increasing or decreasing order. 
It is commonly used to efficiently solve problems such as finding the next greater or smaller element in an array etc.

Complexity Analysis:

    Time Complexity: O(N), each element from the input array is pushed and popped from the stack exactly once. 
    Therefore, even though there is a loop inside a loop, no element is processed more than twice.
    
    Auxiliary Space: O(N)
*/


#include <iostream>
#include <stack>
#include <vector>
using namespace std;
void printVector(const vector<int>& vec);

//monotonic increasing stack
vector<int> monotonicIncreasing(vector<int> nums){
    int n = nums.size();
    stack<int> st;
    vector<int> result;

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && st.top() > nums[i]) {
            st.pop();
        }
        st.push(nums[i]);
    }

    // Construct the result array from the stack in REVERSE order
    while (!st.empty()) {
        result.insert(result.begin(), st.top());
        st.pop();
    }

    return result;
}

vector<int> monotonicDecreasing(vector<int> nums) {
    int n = nums.size();
    stack<int> st;
    vector<int> result;

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && st.top() < nums[i]) {
            st.pop();
        }
        st.push(nums[i]);
    }

    // Construct the result array from the stack in REVERSE order
    while (!st.empty()) {
        result.insert(result.begin(), st.top());
        st.pop();
    }

    return result;
}

int main() {
    vector<int> nums = {10, 3, 1, 4, 1, 5, 9, 7, 2, 6, 5, 3, 5, 9, 8, 5, 3};
    cout << "Input array: ";
    printVector(nums);

    vector<int> result = monotonicIncreasing(nums);
    cout << "Monotonic increasing stack: ";
    printVector(result);



    vector<int> result2 = monotonicDecreasing(nums);
    cout << "Monotonic decreasing stack: ";
    printVector(result2);

    return 0;
}

void printVector(const vector<int>& vec) {
    for (const auto& elem : vec) {
        cout << elem << " ";
    }
    cout << endl;
}