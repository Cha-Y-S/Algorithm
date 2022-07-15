from copy import copy
import sys

N = int(sys.stdin.readline())

seq = list(map(int, sys.stdin.readline().split()))
dp = copy(seq)

for i in range(1, N):
    for j in range(i - 1, -1, -1):
        if seq[i] > seq[j]:
            dp[i] = max(dp[i], dp[j] + seq[i])

sys.stdout.write(str(max(dp)) + "\n")
