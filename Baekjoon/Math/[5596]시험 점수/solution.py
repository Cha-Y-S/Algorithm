import sys

sum1 = sum(list(map(int,sys.stdin.readline().split())))
sum2 = sum(list(map(int,sys.stdin.readline().split())))

sys.stdout.write(str(sum1 if sum1 > sum2 else sum2) + "\n")