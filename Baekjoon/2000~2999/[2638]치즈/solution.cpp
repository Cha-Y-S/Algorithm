#include <iostream>
#include <queue>
#include <vector>

#define endl "\n"

using namespace std;

typedef pair<int, int> pii;

vector<vector<int>> matrix;
vector<vector<bool>> visited;
vector<pii> dirs;
int N, M, res;

int bfs();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

  matrix = vector<vector<int>>(N, vector<int>(M));
  dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> matrix[i][j];
    }
  }

  while (true) {
    visited = vector<vector<bool>>(N, vector<bool>(M, false));

    if (bfs() == 0) {
      break;
    }

    res++;
  }

  cout << res << endl;

  return 0;
}

int bfs() {
  queue<pii> q;
  vector<pii> candidates;
  vector<vector<int>> copied(N, vector<int>(M));
  copy(matrix.begin(), matrix.end(), copied.begin());
  int result = 0;

  q.push({0, 0});
  visited[0][0] = true;
  copied[0][0] = -1;

  while (!q.empty()) {
    int cx = q.front().first;
    int cy = q.front().second;

    q.pop();

    for (int i = 0; i < dirs.size(); i++) {
      int nx = cx + dirs[i].first;
      int ny = cy + dirs[i].second;

      if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

      if (!visited[nx][ny]) {
        if (matrix[nx][ny] == 1) {
          candidates.push_back({nx, ny});
        } else {
          q.push({nx, ny});
          copied[nx][ny] = -1;
        }
        visited[nx][ny] = true;
      }
    }
  }

  for (int i = 0; i < candidates.size(); i++) {
    int x = candidates[i].first;
    int y = candidates[i].second;
    int cnt = 0;

    for (int j = 0; j < dirs.size(); j++) {
      int nx = x + dirs[j].first;
      int ny = y + dirs[j].second;

      if (copied[nx][ny] == -1) cnt++;
    }

    if (cnt >= 2) {
      matrix[x][y] = 0;
      result++;
    }
  }

  return result;
}