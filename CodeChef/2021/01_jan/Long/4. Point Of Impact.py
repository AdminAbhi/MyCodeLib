# =============================================================================
# @abhi_admin    FB UserId: abhiavisekkr     Email Id: abhiavisekkr@gmail.com
# =============================================================================
# ------------------------------Dependencies-----------------------------------
# import sys
# import math
# import cmath
# import array
# import string
# import functools #for .reduce()
# import itertools


# def get_s(): return sys.stdin.readline().strip()
# def get_i(): return map(int, sys.stdin.readline().strip().split())


# =============================================================================
# ----------------------------Keep-Calm-and-Code-------------------------------
# =============================================================================


T = int(input())
for t in range(T):
    N, K, x, y = map(int, input().split())
    cor = set()
    cor.add((1, 1)), cor.add((1, N)), cor.add((N, N)), cor.add((N, 1))
    K %= 4
    N -= 1
    step = N - x
    print(cor)


# =============================================================================
# -----------------------------ADMIN-ABHI-SHAKE--------------------------------
# =============================================================================