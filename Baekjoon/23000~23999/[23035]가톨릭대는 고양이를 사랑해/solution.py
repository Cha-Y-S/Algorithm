import sys

N, M = map(int, sys.stdin.readline().split())
T = int(sys.stdin.readline())

cats = [[] for i in range(T)]
lis = []


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


for i in range(T):
    r, c = map(int, sys.stdin.readline().split())
    cats[i] = [r, c]

cats.sort(key=lambda x: (x[0], x[1]))

for i in range(T):
    if cats[i][0] > N or cats[i][1] > M:
        continue

    if len(lis) == 0 or lis[len(lis) - 1] <= cats[i][1]:
        lis.append(cats[i][1])
    else:
        idx = upper_bound(cats[i][1])
        lis[idx] = cats[i][1]

sys.stdout.write(str(len(lis)) + "\n")
