#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<int, int> pii;

vector<vector<char>> matrix;
vector<vector<bool>> visited;
vector<pii> dir;
int N, M, K, res;

int bfs(int sx, int sy);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M >> K;

  matrix = vector<vector<char>>(N, vector<char>(M, '.'));
  visited = vector<vector<bool>>(N, vector<bool>(M, false));
  dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  res = 0;

  for (int i = 0; i < K; i++) {
    int r, c;

    cin >> r >> c;

    matrix[r - 1][c - 1] = '#';
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (visited[i][j]) continue;

      if (matrix[i][j] == '#') {
        int result = bfs(i, j);

        res = result < res ? res : result;
      }
    }
  }

  cout << res << endl;

  return 0;
}

int bfs(int sx, int sy) {
  queue<pii> q;
  int result = 0;

  q.push({sx, sy});
  visited[sx][sy] = true;

  while (!q.empty()) {
    int cx = q.front().first;
    int cy = q.front().second;
    result++;

    q.pop();

    for (int i = 0; i < dir.size(); i++) {
      int nx = cx + dir[i].first;
      int ny = cy + dir[i].second;

      if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

      if (!visited[nx][ny] && matrix[nx][ny] == '#') {
        q.push({nx, ny});
        visited[nx][ny] = true;
      }
    }
  }

  return result;
}