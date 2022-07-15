N, K = map(int, input().split())
nations = []
res = 0

for i in range(N):
    nations.append(list(map(int, input().split())))

nations.sort(key=lambda x: (x[1], x[2], x[3]), reverse=True)

for i in range(N):
    if nations[i][0] == K:
        res = i

for i in range(N):
    if nations[res][1:] == nations[i][1:]:
        print(i + 1)
        break
