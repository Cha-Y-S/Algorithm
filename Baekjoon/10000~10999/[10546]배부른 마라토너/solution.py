import sys

N = int(sys.stdin.readline())
player = dict()

for i in range(N):
    p = sys.stdin.readline()

    if p not in player.keys():
        player[p] = 1
        continue

    player[p] += 1

for i in range(N - 1):
    player[sys.stdin.readline()] -= 1

for key, value in player.items():
    if value != 0:
        sys.stdout.write(key + "\n")
        break
