#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<int, int> pii;

vector<vector<bool>> matrix;
vector<vector<bool>> visited;
vector<pii> dir;
vector<int> res;
int M, N, K, lux, luy, rdx, rdy;

int bfs(int sx, int sy);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> M >> N >> K;

  matrix = vector<vector<bool>>(M, vector<bool>(N, true));
  visited = vector<vector<bool>>(M, vector<bool>(N, false));
  dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

  for (int k = 0; k < K; k++) {
    cin >> lux >> luy >> rdx >> rdy;

    for (int i = luy; i < rdy; i++) {
      for (int j = lux; j < rdx; j++) {
        matrix[i][j] = false;
      }
    }
  }

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      if (!visited[i][j] && matrix[i][j])
        res.push_back(bfs(i, j));
    }
  }

  sort(res.begin(), res.end());

  cout << res.size() << endl;
  for (int i = 0; i < res.size(); i++)
    cout << res[i] << " ";
  cout << endl;

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

      if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;

      if (!visited[nx][ny] && matrix[nx][ny]) {
        q.push({nx, ny});
        visited[nx][ny] = true;
      }
    }
  }

  return result;
}