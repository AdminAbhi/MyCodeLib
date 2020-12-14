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
    req = int(input())
    board = [list("X"*8) for i in range(8)]
    board[0][0] = 'O'
    cnt = 0
    for i in range(8):
        foo = 0
        for j in range(8):
            if board[i][j] == 'O':
                cnt += 1
            else:
                board[i][j] = '.'
                cnt += 1
            if cnt == req:
                foo = 1
                break
        if foo == 1:
            break

    for i in board:
        print(*i, sep='')
    print()


#==============================================================================
#-----------------------------ADMIN-ABHI-SHAKE---------------------------------
#==============================================================================