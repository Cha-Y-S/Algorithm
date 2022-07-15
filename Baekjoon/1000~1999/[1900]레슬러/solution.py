import sys


class Player:
    def __init__(self, id, power, ring):
        self.id = id
        self.power = power
        self.ring = ring

    def __lt__(self, other):
        return self.power + other.power * self.ring > other.power + self.power * other.ring

    def __str__(self):
        return str(self.id)


N = int(sys.stdin.readline())
players = [Player(0, 0, 0) for i in range(N)]

for i in range(N):
    p, r = map(int, sys.stdin.readline().split())

    players[i] = Player(i + 1, p, r)

players.sort()

for p in players:
    print(p)
