#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<int, int> pii;

vector<vector<int>> color;
vector<vector<int>> gray;
vector<vector<bool>> visited;
vector<pii> dir;
int N, M, T, res;

void bfs(int sx, int sy);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

  color = vector<vector<int>>(N, vector<int>(M * 3));
  gray = vector<vector<int>>(N, vector<int>(M));
  visited = vector<vector<bool>>(N, vector<bool>(M, false));
  dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  res = 0;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M * 3; j++)
      cin >> color[i][j];
  }

  cin >> T;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      gray[i][j] = (color[i][3 * j + 0] + color[i][3 * j + 1] + color[i][3 * j + 2]) / 3;

      gray[i][j] = gray[i][j] >= T ? 255 : 0;
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (!visited[i][j] && gray[i][j] == 255) {
        bfs(i, j);
        res++;
      }
    }
  }

  cout << res << endl;

  return 0;
}

void bfs(int sx, int sy) {
  queue<pii> q;

  q.push({sx, sy});
  visited[sx][sy] = true;

  while (!q.empty()) {
    int cx = q.front().first;
    int cy = q.front().second;

    q.pop();

    for (int i = 0; i < dir.size(); i++) {
      int nx = cx + dir[i].first;
      int ny = cy + dir[i].second;

      if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

      if (!visited[nx][ny] && gray[nx][ny] == 255) {
        q.push({nx, ny});
        visited[nx][ny] = true;
      }
    }
  }
}