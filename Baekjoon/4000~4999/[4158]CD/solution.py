import sys


def lower_bound(value):
    low = 0
    high = len(CD)

    while low < high:
        mid = (low + high) // 2

        if value <= CD[mid]:
            high = mid
        else:
            low = mid + 1

    return high


while(True):
    N, M = map(int, sys.stdin.readline().split())
    res = 0

    if N == 0 and M == 0:
        break

    if N == 0 or M == 0:
        sys.stdout.write(str(0) + "\n")
        continue

    global CD
    CD = [int(sys.stdin.readline()) for i in range(N)]

    for i in range(M):
        num = int(sys.stdin.readline())

        idx = lower_bound(num)

        if idx >= len(CD):
            continue

        if num == CD[idx]:
            res += 1

    sys.stdout.write(str(res) + "\n")
