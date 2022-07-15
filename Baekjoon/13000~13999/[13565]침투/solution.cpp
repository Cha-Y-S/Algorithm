#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<int, int> pii;

vector<vector<bool>> matrix;
vector<vector<bool>> visited;
vector<pii> dir;
string row;
int M, N;
bool res;

bool bfs(int sx, int sy);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> M >> N;

  matrix = vector<vector<bool>>(M, vector<bool>(N));
  visited = vector<vector<bool>>(M, vector<bool>(N, false));
  dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  res = false;

  for (int i = 0; i < M; i++) {
    cin >> row;
    for (int j = 0; j < N; j++)
      matrix[i][j] = row[j] == '0' ? true : false;
  }

  for (int i = 0; i < N; i++) {
    if (!visited[0][i] && matrix[0][i]) res = bfs(0, i);

    if (res) break;
  }

  cout << (res ? "YES" : "NO") << endl;

  return 0;
}

bool bfs(int sx, int sy) {
  queue<pii> q;
  bool result = false;

  q.push({sx, sy});
  visited[sx][sy] = true;

  while (!q.empty()) {
    int cx = q.front().first;
    int cy = q.front().second;

    if (cx == M - 1) {
      result = true;
      break;
    }

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