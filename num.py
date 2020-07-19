number = 50 
low, high = 0 , 100
a = input("give me a number?")
a = int(a)
while a != number :
    if a > number :
        high = a
        a = input("too big range:(%d,%d),G?"\
            %(low,high))
    else :
        low = a
        a = input("too small range:(%d,%d),G?"\
            %(low,high))
    a = int(a)
print("correct")
