N, M = list(map(int, input().split()))
INF = 987654321
res = INF

dp = [[[0 for i in range(3)] for j in range(M + 1)] for k in range(N + 1)]
matrix = []

for i in range(N):
    tmp = list(map(int, input().split()))
    tmp.append(0)
    matrix.append(tmp)
matrix.append([0 for i in range(M + 1)])

for j in range(M):
    for k in range(3):
        dp[0][j][k] = matrix[0][j]

for i in range(1, N + 1):
    for j in range(M):
        if(j == 0):
            dp[i][j][1] = dp[i-1][j+1][0] + matrix[i][j]
            dp[i][j][2] = min(dp[i-1][j+1][0], dp[i-1][j][1]) + matrix[i][j]
        elif(j == M - 1):
            dp[i][j][0] = min(dp[i-1][j][1], dp[i-1][j-1][2]) + matrix[i][j]
            dp[i][j][1] = dp[i-1][j-1][2] + matrix[i][j]
        else:
            dp[i][j][0] = min(dp[i-1][j][1], dp[i-1][j-1][2]) + matrix[i][j]
            dp[i][j][1] = min(dp[i-1][j+1][0], dp[i-1][j-1][2]) + matrix[i][j]
            dp[i][j][2] = min(dp[i-1][j+1][0], dp[i-1][j][1]) + matrix[i][j]

for j in range(M):
    for k in range(3):
        if(dp[N][j][k] == 0):
            continue
        res = min(res, dp[N][j][k])

print(res)
