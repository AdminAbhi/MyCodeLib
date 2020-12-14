import random
T = 20
print(T)
for i in range(T):
    n = 5
    x = random.randint(1, 1000)
    print(n, x)
    for j in range(n):
        print(random.randint(1, 1000), end=' ')
    print()