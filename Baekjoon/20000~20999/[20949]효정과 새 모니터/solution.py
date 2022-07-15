import math


N = int(input())

monitor = [[] for i in range(N)]

for i in range(N):
    W, H = map(int, input().split())

    ppi = math.sqrt(W * W + H * H) / 24

    monitor[i] = [ppi, i + 1]

monitor.sort(key=lambda x: (-x[0], x[1]))

for i in range(N):
    print(monitor[i][1])
