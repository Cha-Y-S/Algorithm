N = int(input())

grade = []
m = {}

for i in range(N):
    nation, student, point = map(int, input().split())

    grade.append([nation, student, point])

grade.sort(key=lambda x: x[2], reverse=True)

cnt = 0
for n, s, p in grade:
    if(cnt == 3):
        break

    if (n in m) and m[n] == 2:
        continue

    if n in m:
        m[n] += 1
    else:
        m[n] = 1

    cnt += 1
    print(n, s)
