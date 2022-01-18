#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<int, int> pii;

vector<vector<char>> matrix;
vector<vector<bool>> visited;
vector<int> vertical;
vector<int> horizontal;
string row;
int N, M;

int bfs(int sx, int sy, char shape);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

  matrix = vector<vector<char>>(N, vector<char>(M));
  visited = vector<vector<bool>>(N, vector<bool>(M, false));

  for (int i = 0; i < N; i++) {
    cin >> row;
    for (int j = 0; j < M; j++)
      matrix[i][j] = row[j];
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (visited[i][j]) continue;

      if (matrix[i][j] == '-')
        horizontal.push_back(bfs(i, j, '-'));
      else
        vertical.push_back(bfs(i, j, '|'));
    }
  }

  cout << horizontal.size() + vertical.size() << endl;

  return 0;
}

int bfs(int sx, int sy, char shape) {
  queue<pii> q;
  int result = 0;

  q.push({sx, sy});
  visited[sx][sy] = true;

  while (!q.empty()) {
    int cx = q.front().first;
    int cy = q.front().second;
    result++;

    q.pop();

    int nx = shape == '-' ? cx : cx + 1;
    int ny = shape == '-' ? cy + 1 : cy;

    if (nx >= N || ny >= M) continue;

    if (!visited[nx][ny] && matrix[nx][ny] == shape) {
      q.push({nx, ny});
      visited[nx][ny] = true;
    }
  }

  return result;
}