N = int(input())
K = input()
res = 0

for s in K:
    if(ord(s) == ord('1')):
        res += 1

print(res)
