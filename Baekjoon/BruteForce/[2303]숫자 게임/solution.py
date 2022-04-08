import sys

N = int(sys.stdin.readline())

players = [[] for i in range(N)]

for p in range(N):
    cards = list(map(int, sys.stdin.readline().split()))

    sum = 0

    for i in range(5):
        for j in range(i + 1, 5):
            for k in range(j + 1, 5):
                tmp = (cards[i] + cards[j] + cards[k]) % 10

                sum = tmp if tmp > sum else sum

    players[p] = [sum, p + 1]

players.sort(key=lambda x: (-x[0], -x[1]))

sys.stdout.write(str(players[0][1]) + "\n")
