import sys

N = int(sys.stdin.readline())
straws = [0 for i in range(N)]
res = -1

for i in range(N):
    straws[i] = int(sys.stdin.readline())

straws.sort(reverse=True)

for i in range(N - 2):
    if(straws[i] < straws[i+1] + straws[i+2]):
        res = straws[i] + straws[i+1] + straws[i+2]
        break

sys.stdout.write(str(res) + "\n")
