import sys

N = int(sys.stdin.readline())
seq = [0 for i in range(N)]
dp = [1 for i in range(N)]

for i in range(N):
    seq[i] = int(sys.stdin.readline())

for i in range(1, N):
    for j in range(i):
        if seq[i] > seq[j]:
            dp[i] = max(dp[i], dp[j] + 1)

sys.stdout.write(str(N - max(dp)) + "\n")
