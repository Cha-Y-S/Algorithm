import sys

day = int(sys.stdin.readline())
car = list(map(int, sys.stdin.readline().split()))
res = 0

for c in car:
    res = res + 1 if day == c else res

sys.stdout.write(str(res) + "\n")
