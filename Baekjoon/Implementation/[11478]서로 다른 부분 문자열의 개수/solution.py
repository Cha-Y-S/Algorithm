import sys

S = sys.stdin.readline()
sub = set()

for i in range(len(S)):
    for j in range(i + 1, len(S)):
        sub.add(S[i:j])

sys.stdout.write(str(len(sub)) + "\n")
