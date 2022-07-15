import sys

N = int(sys.stdin.readline())
seq = list(map(int, sys.stdin.readline().split()))
dp = [1 for i in range(N)]

for i in range(1, N):
    for j in range(i - 1, -1, -1):
        if seq[j] > seq[i]:
            dp[i] = max(dp[i], dp[j] + 1)

sys.stdout.write(str(max(dp)) + "\n")
