import sys

N = int(sys.stdin.readline())
pole = [[] for i in range(N)]
dp = [1 for i in range(N)]

for i in range(N):
    pole[i] = list(map(int, sys.stdin.readline().split()))

pole.sort(key=lambda x: x[0])

for i in range(1, N):
    for j in range(i - 1, -1, -1):
        if pole[i][1] > pole[j][1]:
            dp[i] = max(dp[i], dp[j] + 1)

sys.stdout.write(str(N - max(dp)) + "\n")
