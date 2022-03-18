from collections import deque


N, M = map(int, input().split())

number = [0 for i in range(N)]
visited = [False for i in range(N)]
q = deque()
res = 1

for i in range(N):
    number[i] = int(input())

q.append(number[0])
visited[0] = True

while len(q) != 0:
    cur = q.popleft()

    if(cur == M):
        break

    if visited[number[cur]] == False:
        q.append(number[cur])
        visited[number[cur]] = True
        res += 1
    else:
        res = -1

print(res)
