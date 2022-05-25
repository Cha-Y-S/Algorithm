import sys

A = sys.stdin.readline().strip()
B = sys.stdin.readline().strip()
dp = [[0 for i in range(len(B) + 1)] for j in range(len(A) + 1)]

for i in range(1, len(dp)):
    for j in range(1, len(dp[i])):
        if A[i - 1] == B[j - 1]:
            dp[i][j] = dp[i - 1][j - 1] + 1
        else:
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

sys.stdout.write(str(dp[len(A)][len(B)]) + "\n")
