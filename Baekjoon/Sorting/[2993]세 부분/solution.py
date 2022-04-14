import sys

s = sys.stdin.readline().strip()
res = s

for i in range(1, len(s) - 1):
    for j in range(i + 1, len(s)):
        tmp1 = s[:i][::-1]
        tmp2 = s[i:j][::-1]
        tmp3 = s[j:][::-1]

        tmp = tmp1 + tmp2 + tmp3

        res = tmp if res > tmp else res

sys.stdout.write(res + "\n")
