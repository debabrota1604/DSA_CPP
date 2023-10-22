# Given an array of non-negative integers 'nums' and a positive integer target, find two distinct integers such that their product in equal to target.

nums = [2,3,5,10,100, 15,20,25]
target = 15

# Solution:
def solve(nums, target):
    nums.sort();
    iter = 0; iter2= len(nums)-1
    while iter< iter2:
        product = nums[iter]*nums[iter2]
        if product == target:
            return nums[iter], nums[iter2]
        else:
            if product < target:
                iter+=1
            else:
                iter2-=1

def solveNoSorting(nums, target):
    
        
x,y = solve(nums, target)
print(f"The two numbers are: {x} & {y}" )