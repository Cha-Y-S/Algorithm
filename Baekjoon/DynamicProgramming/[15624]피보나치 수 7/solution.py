N = int(input())
MOD = 1000000007

dp = [0 for i in range(1000001)]
dp[1] = 1

for i in range(2, N + 1):
  dp[i] = (dp[i - 1] + dp[i - 2]) % MOD

print(dp[N])