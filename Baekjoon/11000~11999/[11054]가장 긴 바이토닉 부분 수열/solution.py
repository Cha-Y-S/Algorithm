import sys

N = int(sys.stdin.readline())
seq = list(map(int, sys.stdin.readline().split()))
rseq = list(reversed(seq))
dp_asc = [1 for i in range(N)]
dp_desc = [1 for i in range(N)]

for i in range(1, N):
    for j in range(i - 1, -1, -1):
        if seq[i] > seq[j]:
            dp_asc[i] = max(dp_asc[i], dp_asc[j] + 1)
        if rseq[i] > rseq[j]:
            dp_desc[i] = max(dp_desc[i], dp_desc[j] + 1)

lbs_size = 0
for i in range(N):
    lbs_size = max(lbs_size, dp_asc[i] + dp_desc[N - i - 1] - 1)

sys.stdout.write(str(lbs_size) + "\n")
