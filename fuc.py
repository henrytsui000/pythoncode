#!bin/python3
from decimal import *
getcontext().prec = 100
print(Decimal(2**0.5))
def G(x):
    return Decimal(x**2-2)
def DG(x):
    return 2*x

def newton(x,cnt):
    if cnt==0:
        return x
    else:
        return newton(x-G(x)/DG(x),cnt-1)

print(newton(2.0,994))
