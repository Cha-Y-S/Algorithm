import sys

n_format = sys.stdin.readline()
res = 1
flag = 0
MOD = 1_000_000_009

for c in n_format:
    if c == 'c':
        res = (res * (25 if flag == 1 else 26)) % MOD
        flag = 1
    elif c == 'd':
        res = (res * (9 if flag == 2 else 10)) % MOD
        flag = 2

sys.stdout.write(str(res) + "\n")
