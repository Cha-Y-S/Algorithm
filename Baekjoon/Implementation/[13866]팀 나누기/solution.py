import sys

skill = list(map(int, sys.stdin.readline().split()))

print(abs((skill[0] + skill[3]) - (skill[1] + skill[2])))
