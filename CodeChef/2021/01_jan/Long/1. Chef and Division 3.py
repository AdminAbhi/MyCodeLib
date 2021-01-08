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
    n, k, d = map(int, input().split())
    arr = list(map(int, input().split()))
    cnt = 0
    curr = 0
    for ai in arr:
        curr += ai
        if curr >= k:
            cnt += 1
            curr -= k
    cnt = min(d, cnt + curr // k)
    print(cnt)



#=============================================================================
#-----------------------------ADMIN-ABHI-SHAKE--------------------------------
#=============================================================================
