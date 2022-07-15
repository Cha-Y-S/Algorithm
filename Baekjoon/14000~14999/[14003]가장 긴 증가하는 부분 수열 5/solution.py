import sys

N = int(sys.stdin.readline())
A = list(map(int, sys.stdin.readline().split()))
seq = [0 for i in range(N)]
lis = []


def lower_bound(value):
    low = 0
    high = len(lis)

    while low < high:
        mid = (low + high) // 2

        if value <= lis[mid]:
            high = mid
        else:
            low = mid + 1

    return high


for i in range(N):
    idx = lower_bound(A[i])

    if idx == len(lis):
        lis.append(A[i])
    else:
        lis[idx] = A[i]

    seq[i] = idx

target = len(lis) - 1
res = [0 for i in range(len(lis))]

for i in range(len(seq) - 1, -1, -1):
    if(seq[i] == target):
        res[seq[i]] = A[i]
        target -= 1

sys.stdout.write(str(len(lis)) + "\n")

for n in res:
    sys.stdout.write(str(n) + " ")
sys.stdout.write("\n")
