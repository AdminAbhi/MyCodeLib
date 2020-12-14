# ==============================================================================
# @abhi_admin     FB UserId: abhiavisekkr     Email Id: abhiavisekkr@gmail.com
# ==============================================================================
# ------------------------------Dependencies------------------------------------
# import sys
import math
# import array
# import string
# import functools #for .reduce()
# import itertools


# def get_s(): return sys.stdin.readline().strip()
# def get_i(): return map(int, sys.stdin.readline().strip().split())
# def get_li(): return list(map(int, sys.stdin.readline().strip().split()))


# ==============================================================================
# ----------------------------Keep-Calm-and-Code--------------------------------
# ==============================================================================


T = int(input())
for t in range(T):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    dict_g = {}
    dict_a = {}
    dict_b = {}

    for i in a:
        if i in dict_a: dict_a[i] += 1
        else: dict_a[i] = 1
        if i in dict_g: dict_g[i] += 1
        else: dict_g[i] = 1

    for i in b:
        if i in dict_b: dict_b[i] += 1
        else: dict_b[i] = 1
        if i in dict_g: dict_g[i] += 1
        else: dict_g[i] = 1

    foo = False
    for i in dict_g:
        if dict_g[i] % 2 != 0:
            foo = True
            break
        else:
            dict_g[i] //= 2
    if foo:
        print(-1)
        continue

    #print("possible")

    list_a = []
    list_b = []

    for i in dict_g:
        if i in dict_a:
            if dict_a[i] > dict_g[i]:
                for j in range(dict_a[i] - dict_g[i]):
                    list_a.append(i)
            else:
                for j in range(dict_g[i] - dict_a[i]):
                    list_b.append(i)
        else:
            for j in range(dict_g[i]):
                list_b.append(i)

    if len(list_a) == 0:
        print(0)
        continue

    cost = 0
    mini = min(min(a), min(b), min(list_a), min(list_b))
    list_a.sort(reverse=True)
    list_b.sort(reverse=True)
    l = len(list_a)
    for i in range(l):
        min1 = list_a[-1]
        min2 = list_b[-1]
        if min(min1, min2) < 2*mini:
            if min1 == min(min1, min2):
                cost += min1
                list_a.pop()
            else:
                cost += min2
                list_b.pop()
        else:
            cost += 2*mini
            list_a.pop()
            list_b.pop()
    print(cost)

# ==============================================================================
# -----------------------------ADMIN-ABHI-SHAKE---------------------------------
# ==============================================================================