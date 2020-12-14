#=============================================================================
# @abhi_admin    FB UserId: abhiavisekkr     Email Id: abhiavisekkr@gmail.com
#=============================================================================
#------------------------------Dependencies-----------------------------------
#import sys
import math
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
    n, d = map(int, input().split())
    l = list(map(int, input().split()))
    risk = []
    norisk = []
    for age in l:
        if age >= 80 or age <= 9:
            risk.append(age)
        else:
            norisk.append(age)
    print(math.ceil(len(risk) / d) + math.ceil(len(norisk) / d))



#=============================================================================
#-----------------------------ADMIN-ABHI-SHAKE--------------------------------
#=============================================================================