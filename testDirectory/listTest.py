list1 = [1,2,3,4,5]
print(list1)


list2 = [4,5,6,7]

list1.extend(list2)

print(list1)

# shallow vs deep copy in python
import copy

list3 = list1
list4 = list1[:]
list5 = copy.deepcopy(list1)

list1.append(9)
print("original list now:")
print(list1)
print("shallow copy")
print(list3)


print("two sets of deep copy")
print(list4)
print(list5)