import math

N=math.factorial(100)
Sum=0
while N!=0:
    Sum+=N%10
    N/=10

print Sum
