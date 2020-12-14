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




d1, v1, d2, v2, p = map(int, input().split())

active1 = False
active2 = False
tot = 0

for i in range(1, 200000):
    if d1 == i:
        active1 = True
    if d2 == i:
        active2 = True
    
    if active1 == True:
        tot += v1
    if active2 == True:
        tot += v2
        
    if tot >= p:
        print(i)
        break;
        
    
    



#=============================================================================
#-----------------------------ADMIN-ABHI-SHAKE--------------------------------
#=============================================================================