number = [0 for i in range(5)]
grade = [[] for i in range(8)]
res = 0

for i in range(8):
    point = int(input())
    grade[i] = [point, i + 1]

grade.sort(key=lambda x: x[0], reverse=True)

for i in range(5):
    res += grade[i][0]
    number[i] = grade[i][1]

print(res)

number.sort()

for n in number:
    print(n, end=" ")
