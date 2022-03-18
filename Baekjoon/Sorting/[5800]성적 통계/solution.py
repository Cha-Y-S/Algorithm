from copy import copy


K = int(input())

grade = [[] for i in range(K)]

for i in range(K):
    row = list(map(int, input().split()))

    N = row[0]

    grade[i] = copy(row[1:])

    grade[i].sort()

    print("Class %d" % (i + 1))
    print("Max %d, " % grade[i][N - 1], end="")
    print("Min %d, " % grade[i][0], end="")

    gap = 0

    for j in range(1, N):
        tmp = grade[i][j] - grade[i][j-1]

        gap = tmp if tmp > gap else gap

    print("Largest gap %d" % gap)
