#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<int, int> pii;

vector<vector<int>> matrix;
vector<vector<bool>> visited;
vector<pii> dir;
int N;
bool res;

void bfs();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;
  matrix = vector<vector<int>>(N, vector<int>(N));
  visited = vector<vector<bool>>(N, vector<bool>(N, false));
  dir = {{0, 1}, {1, 0}};
  res = false;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++)
      cin >> matrix[i][j];
  }

  bfs();

  cout << (res ? "HaruHaru" : "Hing") << endl;

  return 0;
}

void bfs() {
  queue<pii> q;

  q.push({0, 0});
  visited[0][0] = true;

  while (!q.empty()) {
    int cx = q.front().first;
    int cy = q.front().second;

    if (cx == N - 1 && cy == N - 1) {
      res = true;
      break;
    }

    q.pop();

    for (int i = 0; i < dir.size(); i++) {
      int nx = cx + matrix[cx][cy] * dir[i].first;
      int ny = cy + matrix[cx][cy] * dir[i].second;

      if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

      if (!visited[nx][ny]) {
        q.push({nx, ny});
        visited[nx][ny] = true;
      }
    }
  }
}