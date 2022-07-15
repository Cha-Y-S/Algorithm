import sys

res_min = 100
res_sum = 0

for i in range(7):
    num = int(sys.stdin.readline())

    if num % 2 != 0:
        res_min = num if res_min > num else res_min
        res_sum += num

if res_sum == 0:
    sys.stdout.write("-1\n")
else:
    sys.stdout.write(str(res_sum) + "\n" + str(res_min) + "\n")
