#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<int, int> pii;

vector<vector<int>> matrix;
vector<vector<int>> dp;
vector<pii> dir;
int M, N, res;

int dfs(int cx, int cy, int cv);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> M >> N;

  matrix = vector<vector<int>>(M, vector<int>(N));
  dp = vector<vector<int>>(M, vector<int>(N, -1));
  dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  res = 0;

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++)
      cin >> matrix[i][j];
  }

  cout << dfs(0, 0, matrix[0][0]) << endl;

  return 0;
}

int dfs(int cx, int cy, int cv) {
  if (cx == M - 1 && cy == N - 1) return 1;
  if (dp[cx][cy] != -1) return dp[cx][cy];

  dp[cx][cy] = 0;
  for (int i = 0; i < dir.size(); i++) {
    int nx = cx + dir[i].first;
    int ny = cy + dir[i].second;

    if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;

    if (matrix[nx][ny] < cv)
      dp[cx][cy] += dfs(nx, ny, matrix[nx][ny]);
  }

  return dp[cx][cy];
}
