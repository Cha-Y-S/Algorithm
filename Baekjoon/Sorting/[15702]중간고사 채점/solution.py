N, M = map(int, input().split())

info = [[]for i in range(M)]
point = list(map(int, input().split()))

id, grade = (0, 0)

for i in range(M):
    row = input().split()

    id = int(row[0])
    grade = 0

    for j in range(N):
        if(row[j+1] == 'O'):
            grade += point[j]

    info[i] = [grade, id]

info.sort(key=lambda x: (-x[0], x[1]))

print(info[0][1], info[0][0])
