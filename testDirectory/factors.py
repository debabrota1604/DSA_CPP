import math

num = int(input("Enter your number: "))
factors = set()

for iter in range(1,math.floor(math.sqrt(num))+1):
    if num % iter ==0:
        factors.add(int(iter))
        factors.add(int(num/iter))

print("Factors of " + str(num) + " are: ")
print(factors)
