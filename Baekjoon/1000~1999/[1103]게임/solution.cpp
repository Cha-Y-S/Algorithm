#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define MAX(X, Y) (X > Y ? X : Y)
#define endl "\n"

typedef pair<int, int> pii;

vector<vector<int>> matrix, dp;
vector<vector<bool>> visited;
vector<pii> dirs;
int N, M, res;

int dfs(int x, int y);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

  matrix = vector<vector<int>>(N, vector<int>(M));
  dp = vector<vector<int>>(N, vector<int>(M, -1));
  visited = vector<vector<bool>>(N, vector<bool>(M, false));
  dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

  for (int i = 0; i < N; i++) {
    string row;

    cin >> row;

    for (int j = 0; j < M; j++) {
      if (row[j] == 'H') {
        matrix[i][j] = -1;
      } else {
        matrix[i][j] = row[j] - '0';
      }
    }
  }

  res = dfs(0, 0);

  cout << res << endl;

  return 0;
}

int dfs(int x, int y) {
  if (x < 0 || y < 0 || x >= N || y >= M || matrix[x][y] == -1) return 0;

  if (visited[x][y]) {
    cout << -1 << endl;
    exit(0);
  }

  if (dp[x][y] != -1) return dp[x][y];

  visited[x][y] = true;
  dp[x][y] = 0;

  for (int i = 0; i < dirs.size(); i++) {
    int nx = x + matrix[x][y] * dirs[i].first;
    int ny = y + matrix[x][y] * dirs[i].second;

    dp[x][y] = MAX(dp[x][y], dfs(nx, ny) + 1);
  }

  visited[x][y] = false;

  return dp[x][y];
}