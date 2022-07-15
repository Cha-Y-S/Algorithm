import sys

A, B = map(int, sys.stdin.readline().split())
res = idx = 0
v = [0 for i in range(1000)]

for i in range(1, 1000):
    for j in range(i):
        if idx >= 1000:
            break
        v[idx] = i
        idx += 1

for i in range(A - 1, B):
    res += v[i]

sys.stdout.write(str(res) + "\n")
