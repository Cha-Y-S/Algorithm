N = int(input())
MAX = 117

dp = [0 for i in range(MAX)]

dp[1] = dp[2] = dp[3] = 1

for i in range(4, N + 1):
  dp[i] = dp[i - 1] + dp[i - 3]

print(dp[N])