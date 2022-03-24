while True:
    N = int(input())

    if(N == 0):
        break

    students = []

    for i in range(N):
        name, height = input().split()

        students.append([name, float(height)])

    students.sort(key=lambda x: x[1], reverse=True)

    tmp = students[0][1]

    for i in range(N):
        if students[i][1] != tmp:
            break
        print(students[i][0], end=" ")
    print()
