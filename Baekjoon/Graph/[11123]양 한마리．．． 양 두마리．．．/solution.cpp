#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<int, int> pii;

vector<vector<int>> matrix;
vector<vector<bool>> visited;
vector<pii> dir;
int T, H, W, res;

void bfs(int x, int y);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> T;

  dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

  for (; T > 0; T--) {
    cin >> H >> W;

    matrix = vector<vector<int>>(H, vector<int>(W));
    visited = vector<vector<bool>>(H, vector<bool>(W, false));
    res = 0;

    for (int i = 0; i < H; i++) {
      string row;

      cin >> row;
      for (int j = 0; j < W; j++) {
        matrix[i][j] = row[j];
      }
    }

    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        if (!visited[i][j] && matrix[i][j] == '#') {
          bfs(i, j);
          res++;
        }
      }
    }

    cout << res << endl;
  }

  return 0;
}

void bfs(int x, int y) {
  queue<pii> q;

  q.push({x, y});
  visited[x][y] = true;

  while (!q.empty()) {
    int cx = q.front().first;
    int cy = q.front().second;

    q.pop();

    for (int i = 0; i < dir.size(); i++) {
      int nx = cx + dir[i].first;
      int ny = cy + dir[i].second;

      if (nx < 0 || ny < 0 || nx >= H || ny >= W) continue;

      if (!visited[nx][ny] && matrix[nx][ny] == '#') {
        q.push({nx, ny});
        visited[nx][ny] = true;
      }
    }
  }
}