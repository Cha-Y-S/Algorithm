import sys

X = int(sys.stdin.readline())
N = int(sys.stdin.readline())

staff = [[] for i in range(N)]
candidates = dict()
s = []
res = []

for i in range(N):
    row = sys.stdin.readline().split()

    staff[i] = [row[0], int(row[1])]

    if staff[i][1] / X * 100 >= 5:
        candidates[staff[i][0]] = 0

        for j in range(14):
            s.append([staff[i][1] / (j+1), staff[i][0]])

s.sort(key=lambda x: x[0], reverse=True)

for i in range(14):
    candidates[s[i][1]] += 1

candidates = sorted(candidates.items())

for k, v in candidates:
    res.append([k, v])

for i in range(len(res)):
    sys.stdout.write(res[i][0] + " " + str(res[i][1]) + "\n")
