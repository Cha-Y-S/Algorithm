import sys

K, L = map(int, sys.stdin.readline().split())
enroll = dict()
res = []

for i in range(L):
    sid = sys.stdin.readline()

    enroll[sid] = i

for key, value in enroll.items():
    res.append([key, value])

res.sort(key=lambda x: (x[1]))

for i in range(len(res)):
    if K > 0:
        sys.stdout.write(res[i][0])
    else:
        break

    K -= 1
