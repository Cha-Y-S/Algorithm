import re
import sys

N = int(sys.stdin.readline())
seq = list(map(int, sys.stdin.readline().split()))
res = []


def lower_bound(value):
    low = 0
    high = len(res)

    while(low < high):
        mid = (low + high) // 2

        if value <= res[mid]:
            high = mid
        else:
            low = mid + 1

    return high


for n in seq:
    idx = lower_bound(n)

    if idx == len(res):
        res.append(n)
    else:
        res[idx] = n

sys.stdout.write(str(len(res)) + "\n")
