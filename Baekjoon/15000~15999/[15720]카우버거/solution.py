from audioop import reverse


B, C, D = map(int, input().split())
max_size = max([B, C, D])
res1 = res2 = 0

burger = sorted(list(map(int, input().split())), reverse=True)
side = sorted(list(map(int, input().split())), reverse=True)
drink = sorted(list(map(int, input().split())), reverse=True)

total = [[] for i in range(max_size)]

for i in range(max_size):
    total[i] = [0, True]
    if i < B:
        total[i][0] += burger[i]
    else:
        total[i][1] = False
    if i < C:
        total[i][0] += side[i]
    else:
        total[i][1] = False
    if i < D:
        total[i][0] += drink[i]
    else:
        total[i][1] = False

for i in range(max_size):
    res1 += total[i][0]

    res2 += int(total[i][0] * 0.9) if total[i][1] == True else total[i][0]

print(res1)
print(res2)
