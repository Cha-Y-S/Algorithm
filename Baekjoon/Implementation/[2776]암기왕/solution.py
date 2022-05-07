import sys

T = int(sys.stdin.readline())

while T != 0:
    N = int(sys.stdin.readline())
    num = list(map(int, sys.stdin.readline().split()))
    note = dict()

    for n in num:
        note[n] = True

    M = int(sys.stdin.readline())
    num = list(map(int, sys.stdin.readline().split()))

    for n in num:
        if note.get(n):
            sys.stdout.write("1\n")
        else:
            sys.stdout.write("0\n")

    T -= 1
