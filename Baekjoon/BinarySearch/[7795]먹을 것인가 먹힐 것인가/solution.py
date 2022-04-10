import sys

T = int(sys.stdin.readline())


def lower_bound(arr, target):
    low = 0
    high = len(arr)

    while low < high:
        mid = low + (high - low) // 2

        if target <= arr[mid]:
            high = mid
        else:
            low = mid + 1

    return high


while T > 0:
    N, M = map(int, sys.stdin.readline().split())

    A = sorted(list(map(int, sys.stdin.readline().split())))
    B = sorted(list(map(int, sys.stdin.readline().split())))
    res = 0

    for i in range(N):
        idx = lower_bound(B, A[i])

        res += idx

    sys.stdout.write(str(res) + "\n")

    T -= 1
