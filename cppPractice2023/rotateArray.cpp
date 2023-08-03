#include <iostream>
#include<vector>
using namespace std;

//function to swap two element
void swap(int &num1, int &num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

//function to reverse
void reverse(vector<int>&nums, int left, int right)
{
    while(left < right)
    {
        swap(nums[left++], nums[right--]);
    }
}

//function to rotate an array by k steps
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;
    reverse(nums, 0, n-1);
    reverse(nums, 0, k-1);
    reverse(nums, k, n-1);
}


//function to print an array
void print(vector<int> nums)
{
    for(int x : nums)
    {
        cout << x << " ";
    }
    cout << "\n";
}

int main()
{
    //input
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    //calling rotate function to rotate the array by k steps
    rotate(nums, k);

    cout << "Array after rotation: ";
    print(nums);
    
    return 0;
}