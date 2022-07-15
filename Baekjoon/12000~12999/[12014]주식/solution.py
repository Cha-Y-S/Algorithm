import sys

T = int(sys.stdin.readline())
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


for t in range(T):
    sys.stdout.write("Case #" + str(t + 1) + "\n")

    N, K = map(int, sys.stdin.readline().split())
    inputData = list(map(int, sys.stdin.readline().split()))

    for n in inputData:
        idx = lower_bound(n)

        if idx == len(lis):
            lis.append(n)
        else:
            lis[idx] = n

    sys.stdout.write("1\n" if K <= len(lis) else "0\n")

    lis.clear()
