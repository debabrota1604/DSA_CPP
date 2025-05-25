#include<bits/stdc++.h>
using namespace std;

int binarySearch(const vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
            return mid;
        if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    vector<int> numbers = {2, 3, 4, 10, 40};
    int target = 10;
    int index = binarySearch(numbers, target);
    if (index == -1)
        cout << "Not found";
    else
        cout << "Found at index " << index;
    return 0;
}