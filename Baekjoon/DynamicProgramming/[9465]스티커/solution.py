import sys

T = int(sys.stdin.readline())

while T != 0:
    N = int(sys.stdin.readline())

    sticker = [[] for i in range(2)]
    dp = [[0 for i in range(N)] for i in range(2)]

    for i in range(2):
        sticker[i] = list(map(int, sys.stdin.readline().split()))

    dp[0][0] = sticker[0][0]
    dp[1][0] = sticker[1][0]

    if N > 1:
        dp[0][1] = sticker[0][1] + dp[1][0]
        dp[1][1] = sticker[1][1] + dp[0][0]

    for i in range(2, N):
        dp[0][i] = sticker[0][i] + max(dp[1][i-1], dp[1][i-2])
        dp[1][i] = sticker[1][i] + max(dp[0][i-1], dp[0][i-2])

    sys.stdout.write(str(max(dp[0][N-1], dp[1][N-1])) + "\n")

    T -= 1
