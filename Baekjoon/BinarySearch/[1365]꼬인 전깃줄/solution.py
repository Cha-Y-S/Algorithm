import sys

N = int(sys.stdin.readline())
inputData = map(int, sys.stdin.readline().split())
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


for n in inputData:
    idx = lower_bound(n)

    if idx == len(lis):
        lis.append(n)
    else:
        lis[idx] = n

sys.stdout.write(str(N - len(lis)) + "\n")
