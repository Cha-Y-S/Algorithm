N, K = map(int, input().split())
dp = [[0 for i in range(j + 1)] for j in range(N)]

for i in range(N):
    for j in range(len(dp[i])):
        if(j == 0):
            dp[i][j] = 1
            continue
        if(j == len(dp[i]) - 1):
            dp[i][j] = 1
            break
        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]

print(dp[N-1][K-1])
