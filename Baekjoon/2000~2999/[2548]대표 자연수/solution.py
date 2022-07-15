import sys

N = int(sys.stdin.readline())
naturals = sorted(list(map(int, sys.stdin.readline().split())))

q, r = divmod(N, 2)

sys.stdout.write(str(naturals[q + r - 1]))
