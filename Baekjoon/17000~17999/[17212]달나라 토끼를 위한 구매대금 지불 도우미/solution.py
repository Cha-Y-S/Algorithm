N = int(input())
MAX = 100001
dp = [0 for i in range(MAX)]

dp[1] = dp[2] = dp[5] = dp[7] = 1
dp[3] = dp[4] = dp[6] = 2

for i in range(8, N + 1):
    dp[i] = min({dp[i-1] + 1, dp[i-2] + 1, dp[i-5] + 1, dp[i-7] + 1})

print(dp[N])
