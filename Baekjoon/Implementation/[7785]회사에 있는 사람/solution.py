import sys

N = int(sys.stdin.readline())
company = set()

for i in range(N):
    name, info = map(str, sys.stdin.readline().split())

    if info == "enter":
        company.add(name)
    else:
        company.remove(name)

for person in sorted(company, reverse=True):
    sys.stdout.write(person + "\n")
