import sys

low = 100
res = 0

for i in range(4):
    point = int(sys.stdin.readline())

    low = point if low > point else low

    res += point

res -= low
low = 100

for i in range(2):
    point = int(sys.stdin.readline())

    low = point if low > point else low

    res += point

res -= low

sys.stdout.write(str(res) + "\n")
