import sys

N = int(sys.stdin.readline())
dp = [[] for i in range(N + 3)]

dp[1] = [0, 0]
dp[2] = [1, 1]
dp[3] = [1, 1]

for i in range(4, N + 1):
    dp[i] = [dp[i-1][0] + 1, i - 1]

    if i % 2 == 0:
        if dp[i][0] > dp[i//2][0] + 1:
            dp[i] = [dp[i//2][0] + 1, i // 2]

    if i % 3 == 0:
        if dp[i][0] > dp[i//3][0] + 1:
            dp[i] = [dp[i//3][0] + 1, i // 3]

sys.stdout.write(str(dp[N][0]) + "\n")

idx = N

while idx > 0:
    sys.stdout.write(str(idx) + " ")

    idx = dp[idx][1]

sys.stdout.write("\n")
