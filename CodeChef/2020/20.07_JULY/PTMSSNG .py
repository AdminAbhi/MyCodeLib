#==============================================================================
# @abhi_admin     FB UserId: abhiavisekkr     Email Id: abhiavisekkr@gmail.com
#==============================================================================
#------------------------------Dependencies------------------------------------
#import sys
#import math
#import array
#import string
#import functools #for .reduce()
#import itertools


#def get_s(): return sys.stdin.readline().strip()
#def get_i(): return map(int, sys.stdin.readline().strip().split())
#def get_li(): return list(map(int, sys.stdin.readline().strip().split()))


#==============================================================================
#----------------------------Keep-Calm-and-Code--------------------------------
#==============================================================================


T = int(input())
for t in range(T):
    n = int(input())
    dict_x = {}
    dict_y = {}
    for i in range(4*n-1):
        x, y = map(int, input().split())
        if x in dict_x:
            dict_x[x].append(y)
        else:
            dict_x[x] = [y]
        if y in dict_y:
            dict_y[y].append(x)
        else:
            dict_y[y] = [x]

    xi, yi = 0, 0
    for i in dict_x:
        if len(dict_x[i]) % 2 != 0:
            xi = i
            break
    for i in dict_y:
        if len(dict_y[i]) % 2 != 0:
            yi = i
            break
    print(xi, yi)

#==============================================================================
#-----------------------------ADMIN-ABHI-SHAKE---------------------------------
#==============================================================================