def chainLength(x):
    res = 1
    while (x > 1):
        res += 1
        if (x % 2): x = 3 * x + 1
        else: x /= 2
    return res

ans = 0

for i in range(1, 1000000):
    ans = max(ans, chainLength(i))

print(ans)