import sys

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


while True:
    N = sys.stdin.readline()
    if not N:
        break
    N = int(N)
    inputData = list(map(int, sys.stdin.readline().split()))

    for n in inputData:
        idx = lower_bound(n)

        if idx == len(lis):
            lis.append(n)
        else:
            lis[idx] = n

    sys.stdout.write(str(len(lis)) + "\n")

    lis.clear()
