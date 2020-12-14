# ==============================================================================
# @abhi_admin     FB UserId: abhiavisekkr     Email Id: abhiavisekkr@gmail.com
# ==============================================================================
# ------------------------------Dependencies------------------------------------
# import sys
# import math
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


def sol(n, x, arr):
    maxi = max(arr)
    if x >= maxi:
        return n
    nod = 0
    a = []
    b = []
    for i in arr:
        if i <= x:
            nod += 1
            b.append(i)
        else:
            a.append(i)
    a.sort(reverse=True)
    b.sort()
    if x in arr:
        x *= 2
    elif 2*x < (a[-1]+1)//2 and 2*b[-1] >= (a[-1]+1)//2:
        x = 2*b[-1]


    while len(a) > 0:
        a[0] = min(maxi, 2 * a[0])
        #print(a, "nod= ", nod, "x= ", x)
        if x >= a[0]:
            return nod + len(a)
        nod += 1
        if x in a:
            a.remove(x)
            x *= 2
            continue

        foo = False
        while len(a) > 0 and x > a[-1]:
            if len(a) > 1 and 2 * a[-1] >= (a[-2] if len(a) > 2 else min(maxi, 2 * a[-2])):
                if 2 * a[-1] == (a[-2] if len(a) > 2 else min(maxi, 2 * a[-2])):
                    if len(a) == 2:
                        return nod + 1
                    else:
                        x = a[-2] * 2
                        nod += 1
                        a.pop()
                        a.pop()
                    foo = True
                    break
                else:
                    x = a[-2]*2
                    nod += 1
                    a.pop()
                    a.pop()
            else:
                #nod += 1
                a.pop()
        if foo: continue

        if len(a) == 0:
            break

        if x >= (a[0]+1)//2:
            return nod + len(a)

        a[0] -= x
        x *= 2

    return nod



T = int(input())
while T > 0:
    n, x = map(int, input().split())
    arr = list(map(int, input().split()))

    print(sol(n, x, arr))

    T -= 1


# ==============================================================================
# -----------------------------ADMIN-ABHI-SHAKE---------------------------------
# ==============================================================================