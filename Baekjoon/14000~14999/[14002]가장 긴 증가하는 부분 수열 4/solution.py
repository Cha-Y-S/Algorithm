import sys

N = int(sys.stdin.readline())
seq = list(map(int, sys.stdin.readline().split()))
dp = [1 for i in range(N)]

for i in range(1, N):
    for j in range(i - 1, -1, -1):
        if seq[i] > seq[j]:
            dp[i] = max(dp[i], dp[j] + 1)

target = max(dp)
lis = [0 for i in range(target)]

for i in range(N - 1, -1, -1):
    if dp[i] == target:
        lis[target - 1] = seq[i]
        target -= 1

sys.stdout.write(str(len(lis)) + "\n")

for n in lis:
    sys.stdout.write(str(n) + " ")
sys.stdout.write("\n")
