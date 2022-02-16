R, C, W = map(int, input().split())
dp = [[0 for i in range(j+1)] for j in range(30)]
res = 0

for i in range(30):
    for j in range(len(dp[i])):
        if(j == 0):
            dp[i][j] = 1
            continue
        if(j == len(dp[i])-1):
            dp[i][j] = 1
            continue
        dp[i][j] = dp[i-1][j-1] + dp[i-1][j]

for i in range(R - 1, R + W - 1):
    for j in range(C - 1, C + i - R + 1):
        res += dp[i][j]

print(res)