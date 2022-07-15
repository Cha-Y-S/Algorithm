N = int(input())
MAX = 1000001
MOD = 1000000000
tmp = abs(N)

dp = [0 for i in range(MAX)]
dp[1] = 1

for i in range(2, tmp + 1):
    dp[i] = (dp[i-1] + dp[i-2]) % MOD

print(0 if N == 0 else (-1 if (N < 0 and tmp % 2 == 0) else 1))
print(dp[tmp])
