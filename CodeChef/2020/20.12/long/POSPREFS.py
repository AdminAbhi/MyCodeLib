#=============================================================================
# @abhi_admin    FB UserId: abhiavisekkr     Email Id: abhiavisekkr@gmail.com
#=============================================================================
#------------------------------Dependencies-----------------------------------
#import sys
#import math
#import cmath
#import array
#import string
#import functools #for .reduce()
#import itertools 


#def get_s(): return sys.stdin.readline().strip() 
#def get_i(): return map(int, sys.stdin.readline().strip().split())


#=============================================================================
#----------------------------Keep-Calm-and-Code-------------------------------
#=============================================================================




T = int(input())
for t in range(T):
    n, k = map(int, input().split())
    suum = 0
    res = []
    not_k = n - k
    for i in range(1, n+1):
        if k > 0:
            if n - i + 1 == k:
                res.append(i)
                k -= 1
                suum += i
            elif suum <= 0:
                res.append(i)
                suum += i
                k -= 1
            else:
                res.append(-i)
                suum -= i
                not_k -= 1
        else:
            res.append(-i)
            suum -= i
            not_k -= 1
    
    print(*res)


#=============================================================================
#-----------------------------ADMIN-ABHI-SHAKE--------------------------------
#=============================================================================