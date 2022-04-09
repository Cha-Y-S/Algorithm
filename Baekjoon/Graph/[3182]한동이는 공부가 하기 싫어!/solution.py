from collections import deque
import sys

N = int(sys.stdin.readline())
graph = [0 for i in range(N + 1)]
maximum = 0
res = 0

for i in range(1, N + 1):
    graph[i] = int(sys.stdin.readline())


def bfs(start):
    q = deque()
    visited = [False for i in range(N + 1)]
    result = 0

    q.append(start)
    visited[start] = True

    while q:
        cur = q.popleft()

        result += 1

        if(visited[graph[cur]] == False):
            q.append(graph[cur])
            visited[graph[cur]] = True

    return result


for i in range(1, N + 1):
    tmp = bfs(i)

    if tmp > maximum:
        maximum = tmp
        res = i

sys.stdout.write(str(res) + "\n")
