def bfs(m, v, x, y, H, W):
    dir = [[1, 0], [0, 1], [-1, 0], [0, -1]]
    q = []

    q.append([x, y])
    v[x][y] = True

    while len(q) != 0:
        cx, cy = q.pop(0)

        for i in range(len(dir)):
            nx = cx + dir[i][0]
            ny = cy + dir[i][1]

            if (nx < 0 or ny < 0 or nx >= H or ny >= W):
                continue

            if((visited[nx][ny] == False) and (matrix[nx][ny] == '#')):
                q.append([nx, ny])
                visited[nx][ny] = True


T = int(input())

for t in range(T):
    H, W = map(int, input().split())
    res = 0

    visited = [[False for i in range(W)] for j in range(H)]
    matrix = ["" for i in range(H)]

    for i in range(H):
        matrix[i] = input()

    for i in range(len(matrix)):
        for j in range(len(matrix[i])):
            if ((visited[i][j] == False) and (matrix[i][j] == '#')):
                bfs(matrix, visited, i, j, H, W)
                res += 1

    print(res)
