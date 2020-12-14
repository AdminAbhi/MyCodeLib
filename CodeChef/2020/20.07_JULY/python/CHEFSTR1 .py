#==============================================================================
# @abhi_admin     FB UserId: abhiavisekkr     Email Id: abhiavisekkr@gmail.com
#==============================================================================
#------------------------------Dependencies------------------------------------
import sys
import math
#import array
#import string
#import functools #for .reduce()
#import itertools




#==============================================================================
#----------------------------Keep-Calm-and-Code--------------------------------
#==============================================================================

T = int(input())
for t in range(T):
    r = int(input())
    res = 2
    cp, mp = 0, 0
    for i in range(r):
        c, m = map(int, input().split())
        c = sum(list(map(int, list(str(c)))))
        m = sum(list(map(int, list(str(m)))))
        #print("points : ",c, m)
        if c > m:
            cp += 1
        elif m > c:
            mp += 1
        else:
            cp += 1
            mp += 1
    if cp > mp:
        print(0, cp)
    elif mp > cp:
        print(1, mp)
    else:
        print(2, cp)



#==============================================================================
#-----------------------------ADMIN-ABHI-SHAKE---------------------------------
#==============================================================================