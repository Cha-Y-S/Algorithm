import sys

T = int(sys.stdin.readline())
lis = []
res = 0


def lower_bound(value):
    low = 0
    high = len(lis)

    while low < high:
        mid = (low + high) // 2

        if value < lis[mid]:
            high = mid
        else:
            low = mid + 1

    return high


for t in range(T):
    N = int(sys.stdin.readline())
    seq = [0 for i in range(N)]
    res = 0

    for i in range(N):
        seq[i] = int(sys.stdin.readline())

    for i in range(N):
        lis.clear()
        for j in range(i, N):
            idx = lower_bound(seq[j])

            if idx == len(lis):
                lis.append(seq[j])
            else:
                lis[idx] = seq[j]

            res += len(lis)

    sys.stdout.write("Case #%d: %d\n" % ((t+1), res))
