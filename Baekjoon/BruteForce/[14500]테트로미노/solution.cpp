#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"
#define MAX(X, Y) (X > Y ? X : Y)

typedef pair<int, int> pii;

vector<vector<int>> matrix;
vector<pii> dir;
bool visited[500][500];
int N, M, res;

void dfs(int x, int y, int sum, int depth);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

  matrix = vector<vector<int>>(N, vector<int>(M));

  dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  res = 0;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> matrix[i][j];
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      memset(visited, false, sizeof(visited));
      visited[i][j] = true;
      dfs(i, j, matrix[i][j], 0);
      if (i - 1 >= 0 && j + 2 < M) {
        int temp = matrix[i][j] + matrix[i][j + 1] + matrix[i][j + 2] + matrix[i - 1][j + 1];
        res = MAX(res, temp);
      }
      if (i + 1 < N && j + 2 < M) {
        int temp = matrix[i][j] + matrix[i][j + 1] + matrix[i][j + 2] + matrix[i + 1][j + 1];
        res = MAX(res, temp);
      }
      if (i + 2 < N && j + 1 < M) {
        int temp = matrix[i][j] + matrix[i + 1][j] + matrix[i + 2][j] + matrix[i + 1][j + 1];
        res = MAX(res, temp);
      }
      if (i + 1 < N && i - 1 >= 0 && j + 1 < M) {
        int temp = matrix[i][j] + matrix[i - 1][j + 1] + matrix[i][j + 1] + matrix[i + 1][j + 1];
        res = MAX(res, temp);
      }
    }
  }

  cout << res << endl;

  return 0;
}

void dfs(int x, int y, int sum, int depth) {
  if (depth == 3) {
    res = MAX(res, sum);
    return;
  }

  for (int i = 0; i < dir.size(); i++) {
    int nx = x + dir[i].first;
    int ny = y + dir[i].second;

    if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
    if (visited[nx][ny]) continue;
    visited[nx][ny] = true;
    dfs(nx, ny, sum + matrix[nx][ny], depth + 1);
    visited[nx][ny] = false;
  }
}
