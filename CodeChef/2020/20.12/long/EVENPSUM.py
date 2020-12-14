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
    A, B = map(int, input().split())
    ae = A//2
    ao = A - ae
    be = B//2
    bo = B - be
    print(ae * be + ao * bo)



#=============================================================================
#-----------------------------ADMIN-ABHI-SHAKE--------------------------------
#=============================================================================