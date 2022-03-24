N = int(input())

people = []

for i in range(N):
    name, day, month, year = input().split()

    people.append([name, int(year), int(month), int(day)])

people.sort(key=lambda x: (x[1], x[2], x[3]))

print(people[N-1][0])
print(people[0][0])
