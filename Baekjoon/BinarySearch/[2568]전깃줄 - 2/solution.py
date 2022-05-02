import sys

N = int(sys.stdin.readline())
pole = [[] for i in range(N)]
idxs = [0 for i in range(N)]
lis, res = [[], []]


def lower_bound(value):
    low = 0
    high = len(lis)

    while(low < high):
        mid = (low + high) // 2

        if value <= lis[mid]:
            high = mid
        else:
            low = mid + 1

    return high


for i in range(N):
    pole[i] = list(map(int, sys.stdin.readline().split()))

pole.sort(key=lambda x: (x[0]))

for i in range(N):
    n = pole[i][1]

    idx = lower_bound(n)

    idxs[i] = idx

    if idx == len(lis):
        lis.append(n)
    else:
        lis[idx] = n

target = len(lis) - 1
for i in range(N - 1, -1, -1):
    if target == idxs[i]:
        target -= 1
    else:
        res.append(pole[i][0])

res.sort()

sys.stdout.write(str(N - len(lis)) + "\n")
for n in res:
    sys.stdout.write(str(n) + "\n")
