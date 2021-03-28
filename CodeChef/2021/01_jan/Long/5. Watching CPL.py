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
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    if n == 1:
        print(-1)
        continue

    arr.sort(reverse=True)
    # print(arr)

    sum1, sum2, cnt = 0, 0, 0
    vis = [0] * n
    idx = -1

    for i in range(n):
        if sum1 < k:
            sum1 += arr[i]
            vis[i] = 1
            cnt += 1
        else:
            idx = i
            break

    if sum1 > k and idx != -1:
        for i in range(idx, n):
            for j in range(i):
                if vis[j] == 1 and sum1 - arr[j] + arr[i] >= k:
                    vis[j] = 0
                    vis[i] = 1
                    sum1 = sum1 - arr[j] + arr[i]
                    break

    for i in range(n):
        if vis[i] == 0 and sum2 < k:
            sum2 += arr[i]
            cnt += 1
            vis[i] = 2
        if sum2 >= k:
            break

    # print(vis)
    if sum1 >= k and sum2 >= k:
        print(cnt)
    else:
        print(-1)

# =============================================================================
# -----------------------------ADMIN-ABHI-SHAKE--------------------------------
# =============================================================================