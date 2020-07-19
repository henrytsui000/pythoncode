#!bin/python3
s = input('give?')
handle = open( s , 'r' )
L = handle.readlines()
for i in range( 0 , len(L)):
    if L[i] != L[i-1] :
        print('\r%s' %  L[i])
