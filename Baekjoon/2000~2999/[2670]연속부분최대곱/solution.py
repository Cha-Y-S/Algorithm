N = int(input())

dp = [0 for i in range(N)]

for i in range(N):
    dp[i] = float(input())

res = dp[0]

for i in range(1, N):
    dp[i] = max(dp[i], dp[i - 1] * dp[i])
    res = max(res, dp[i])

print("%.3f" % res)
