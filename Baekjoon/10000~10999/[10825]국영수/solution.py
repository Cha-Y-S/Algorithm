N = int(input())
students = [[] for i in range(N)]

for i in range(N):
    n, k, e, m = input().split()

    students[i] = [int(k), int(e), int(m), n]

students.sort(key=lambda x: (-x[0], x[1], -x[2], x[3]))

for i in range(N):
    print(students[i][3])
