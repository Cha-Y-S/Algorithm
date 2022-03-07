#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"
#define INF 987'654'321

vector<vector<vector<int>>> dp;
vector<vector<int>> matrix;
int N, M, res;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

  dp = vector<vector<vector<int>>>(N + 1, vector<vector<int>>(M + 1, vector<int>(3, 0)));
  matrix = vector<vector<int>>(N + 1, vector<int>(M + 1));
  res = INF;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++)
      cin >> matrix[i][j];
  }

  for (int j = 0; j < M; j++) {
    for (int k = 0; k < 3; k++)
      dp[0][j][k] = matrix[0][j];
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 0; j < M; j++) {
      if (j == 0) {
        dp[i][j][1] = dp[i - 1][j + 1][0] + matrix[i][j];
        dp[i][j][2] = min(dp[i - 1][j][1], dp[i - 1][j + 1][0]) + matrix[i][j];
      } else if (j == M - 1) {
        dp[i][j][0] = min(dp[i - 1][j][1], dp[i - 1][j - 1][2]) + matrix[i][j];
        dp[i][j][1] = dp[i - 1][j - 1][2] + matrix[i][j];
      } else {
        dp[i][j][0] = min(dp[i - 1][j][1], dp[i - 1][j - 1][2]) + matrix[i][j];
        dp[i][j][1] = min(dp[i - 1][j + 1][0], dp[i - 1][j - 1][2]) + matrix[i][j];
        dp[i][j][2] = min(dp[i - 1][j + 1][0], dp[i - 1][j][1]) + matrix[i][j];
      }
    }
  }

  for (int j = 0; j < M; j++) {
    for (int k = 0; k < 3; k++) {
      if (dp[N][j][k] == 0) continue;
      res = min(res, dp[N][j][k]);
    }
  }

  cout << res << endl;

  return 0;
}