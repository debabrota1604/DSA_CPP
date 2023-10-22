import random as rd

heads=0
tails=0

for count in range(1, 1_000_000_000):
    if(rd.randint(0,1)):
        heads +=1
    else:
        tails +=1

print("heads/tails: ", heads/tails)