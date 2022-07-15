from collections import deque


H, W = map(int, input().split())
matrix = [[0 for i in range(W)] for i in range(H)]
visited = []
dirs = [[-1, 0], [0, 1], [1, 0], [0, -1]]
hour = 0
res = 0

for i in range(H):
    row = list(map(int, input().split()))

    for j in range(W):
        matrix[i][j] = row[j]


def bfs():
    q = deque()
    cnt = 0

    q.append([0, 0])
    visited[0][0] = True

    while q:
        cx, cy = q.popleft()

        for i in range(len(dirs)):
            nx = cx + dirs[i][0]
            ny = cy + dirs[i][1]

            if nx < 0 or ny < 0 or nx >= H or ny >= W:
                continue

            if visited[nx][ny] == False:
                if matrix[nx][ny] == 0:
                    q.append([nx, ny])
                else:
                    matrix[nx][ny] = 0
                    cnt += 1
                visited[nx][ny] = True

    return cnt


while True:
    visited = [[False] * W for i in range(H)]
    tmp = bfs()
    hour += 1

    if(tmp == 0):
        hour -= 1
        break

    res = tmp

print(hour)
print(res)
