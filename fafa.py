#!bin/python3
def gogo(tar,nw):
    while nw*nw<tar:
        nw += 1
    return nw - 1

f = open('fafa.txt' , 'w')
n = 10000
r,ans,cnt = 2,0,1
while ans < 10**(n+1):
    r*=100
    ans = gogo(r,ans*10)
f.write(str(ans))
