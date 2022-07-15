import sys

N = int(sys.stdin.readline())
inputData = list(map(int, sys.stdin.readline().split()))
lis = list()


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


for i in range(N):
    idx = lower_bound(inputData[i])

    if idx == len(lis):
        lis.append(inputData[i])
    else:
        lis[idx] = inputData[i]

sys.stdout.write(str(len(lis)) + "\n")
