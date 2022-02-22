N = int(input())

tmp1 = tmp2 = 1
res = 0
MOD = 1000000007

for i in range(3, N + 1):
    res = (tmp1 + tmp2) % MOD
    tmp1 = tmp2
    tmp2 = res

print(res, N - 2)
