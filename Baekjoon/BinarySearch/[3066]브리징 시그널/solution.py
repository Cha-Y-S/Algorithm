import sys

T = int(sys.stdin.readline())
lis = []


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


while T > 0:
    N = int(sys.stdin.readline())

    for i in range(N):
        num = int(sys.stdin.readline())

        idx = lower_bound(num)

        if idx == len(lis):
            lis.append(num)
        else:
            lis[idx] = num

    sys.stdout.write(str(len(lis)) + "\n")

    lis.clear()
    T -= 1
