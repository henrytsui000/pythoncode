arr = [5, -9 ,-6 ,0,7, 4]
neg , pos , ze = 0,0,0
for i in arr:
    if i > 0:
        pos
    elif i<0 :
        neg+=1
    else :
        ze+=1
print(pos , neg , ze)