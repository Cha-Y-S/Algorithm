from collections import deque
from copy import deepcopy


N, M = map(int, input().split())
matrix = [[] for i in range(N)]
visited = []
dirs = [[-1, 0], [0, 1], [1, 0], [0, -1]]
res = 0

for i in range(N):
    matrix[i] = list(map(int, input().split()))


def bfs():
    q = deque()
    copied = deepcopy(matrix)
    candidates = list()
    result = 0

    q.append([0, 0])
    visited[0][0] = True
    copied[0][0] = -1

    while q:
        cx, cy = q.popleft()

        for i in range(len(dirs)):
            nx = cx + dirs[i][0]
            ny = cy + dirs[i][1]

            if nx < 0 or ny < 0 or nx >= N or ny >= M:
                continue

            if visited[nx][ny] == False:
                if matrix[nx][ny] == 1:
                    candidates.append([nx, ny])
                else:
                    q.append([nx, ny])
                    copied[nx][ny] = -1

                visited[nx][ny] = True

    for cx, cy in candidates:
        cnt = 0

        for i in range(len(dirs)):
            nx = cx + dirs[i][0]
            ny = cy + dirs[i][1]

            if copied[nx][ny] == -1:
                cnt += 1

        if cnt >= 2:
            result += 1
            matrix[cx][cy] = 0

    return result


while(True):
    visited = [[False] * M for i in range(N)]

    if bfs() == 0:
        break

    res += 1

print(res)
