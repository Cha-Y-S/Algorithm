import sys

N = int(sys.stdin.readline())
conv, lis = [[], []]
inputData = list(map(int, sys.stdin.readline().split()))
H = [inputData[0], inputData[1]]
W = [inputData[2], inputData[3]]
conv = [0, 0]
errands = [[] for i in range(N)]


def upper_bound(value):
    low = 0
    high = len(lis)

    while low < high:
        mid = (low + high) // 2

        if value < lis[mid]:
            high = mid
        else:
            low = mid + 1

    return high


W[0] -= H[0]
W[1] -= H[1]

if W[0] < 0:
    conv[0] = -1
else:
    conv[0] = 1

if W[1] < 0:
    conv[1] = -1
else:
    conv[1] = 1

for i in range(N):
    x, y = map(int, sys.stdin.readline().split())
    errands[i] = [x, y]

    errands[i][0] -= H[0]
    errands[i][0] *= conv[0]

    errands[i][1] -= H[1]
    errands[i][1] *= conv[1]

H = [0, 0]
W[0] *= conv[0]
W[1] *= conv[1]

errands.sort(key=lambda x: (x[0], x[1]))

for x, y in errands:
    if x < H[0] or x > W[0]:
        continue
    if y < H[1] or y > W[1]:
        continue

    if(len(lis) == 0 or lis[len(lis) - 1] <= y):
        lis.append(y)
    else:
        idx = upper_bound(y)
        lis[idx] = y

sys.stdout.write(str(len(lis)) + "\n")
