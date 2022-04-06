import sys

N = int(sys.stdin.readline())
grade = [0 for i in range(N)]
res = 0

for i in range(N):
    grade[i] = int(sys.stdin.readline())

grade.sort()

for i in range(N):
    res += abs(grade[i] - (i + 1))

print(res)
