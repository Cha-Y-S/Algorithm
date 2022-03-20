#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<int, int> pii;

vector<vector<int>> matrix;
vector<vector<bool>> visited;
vector<pii> dir;
int H, W, hour, res;

int bfs();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> H >> W;

  matrix = vector<vector<int>>(H, vector<int>(W));
  dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  hour = 0;

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> matrix[i][j];
    }
  }

  while (true) {
    visited = vector<vector<bool>>(H, vector<bool>(W, false));
    int tmp = bfs();

    if (tmp == 0) {
      break;
    }

    res = tmp;
  }

  cout << --hour << endl;
  cout << res << endl;

  return 0;
}

int bfs() {
  queue<pii> q;
  int cnt = 0;

  q.push({0, 0});
  visited[0][0] = true;
  hour++;

  while (!q.empty()) {
    int cx = q.front().first;
    int cy = q.front().second;

    q.pop();

    for (int i = 0; i < dir.size(); i++) {
      int nx = cx + dir[i].first;
      int ny = cy + dir[i].second;

      if (nx < 0 || ny < 0 || nx >= H || ny >= W) continue;

      if (!visited[nx][ny]) {
        if (matrix[nx][ny] == 0) {
          q.push({nx, ny});
        } else {
          matrix[nx][ny] = 0;
          cnt++;
        }
        visited[nx][ny] = true;
      }
    }
  }

  return cnt;
}