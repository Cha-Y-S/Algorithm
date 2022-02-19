N = int(input())

dp = [0 for i in range(11)]

dp[1] = 0
dp[2] = 1
dp[3] = 3

for i in range(4, N + 1):
    a = i // 2
    b = i - (i // 2)
    dp[i] = a * b + dp[a] + dp[b]

print(dp[N])
