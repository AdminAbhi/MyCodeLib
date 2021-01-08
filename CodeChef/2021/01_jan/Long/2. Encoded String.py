# =============================================================================
# @abhi_admin    FB UserId: abhiavisekkr     Email Id: abhiavisekkr@gmail.com
# =============================================================================
# ------------------------------Dependencies-----------------------------------
# import sys
# import math
# import cmath
# import array
import string
# import functools #for .reduce()
# import itertools


# def get_s(): return sys.stdin.readline().strip()
# def get_i(): return map(int, sys.stdin.readline().strip().split())


# =============================================================================
# ----------------------------Keep-Calm-and-Code-------------------------------
# =============================================================================



def decode(w):
    alpha = string.ascii_lowercase
    mid = 8
    idx = 0
    for i in w:
        if i == '1':
            idx += mid
        mid = mid // 2
    return alpha[idx]



T = int(input())
for t in range(T):
    n = int(input())
    s = input()
    sl = []
    i = 0
    while i < len(s):
        sl.append(s[i:i+4])
        i += 4
    res = ""
    for w in sl:
        res += decode(w)
    print(res)


# =============================================================================
# -----------------------------ADMIN-ABHI-SHAKE--------------------------------
# =============================================================================