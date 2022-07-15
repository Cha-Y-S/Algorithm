N = int(input())
MOD = 1000000007
MAX = 51

dp = [1 for i in range(MAX)]

for i in range(2, N + 1):
    dp[i] = (dp[i-1] + dp[i-2] + 1) % MOD

print(dp[N])
