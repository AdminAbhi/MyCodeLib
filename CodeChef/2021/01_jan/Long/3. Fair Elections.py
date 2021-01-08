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
    n, m = map(int, input().split())
    l1 = list(map(int, input().split()))
    l2 = list(map(int, input().split()))
    l1.sort()
    l2.sort(reverse=True)

    sum1 = sum(l1)
    sum2 = sum(l2)
    cnt = 0
    i, j = 0, 0
    while i < len(l1) and j < len(l2):
        if sum1 > sum2:
            break;
        if l1[i] < l2[j]:
            cnt += 1
            sum1 += l2[j] - l1[i]
            sum2 -= l2[j] - l1[i]
            i += 1
            j += 1
        else:
            break
    print(cnt if sum1 > sum2 else -1)





# =============================================================================
# -----------------------------ADMIN-ABHI-SHAKE--------------------------------
# =============================================================================