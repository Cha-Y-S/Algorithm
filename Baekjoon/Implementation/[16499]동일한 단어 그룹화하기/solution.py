import sys

N = int(sys.stdin.readline())
s = set()

for i in range(N):
    word = str(sorted(sys.stdin.readline()))
    s.add(word)

sys.stdout.write(str(len(s)) + "\n")
