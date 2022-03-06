#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"
#define MAX 987654321

vector<vector<vector<int>>> dp;
vector<vector<int>> matrix;
int N, M, res;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

  dp = vector<vector<vector<int>>>(N + 1, vector<vector<int>>(M + 1, vector<int>(3, 0)));
  matrix = vector<vector<int>>(N + 1, vector<int>(M + 1));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++)
      cin >> matrix[i][j];
  }

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < 3; j++) {
      dp[0][i][j] = matrix[0][i];
    }
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
        dp[i][j][2] = min(dp[i - 1][j][1], dp[i - 1][j + 1][0]) + matrix[i][j];
      }
    }
  }

  res = MAX;
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < 3; j++) {
      if (dp[N][i][j] == 0) continue;
      res = min(res, dp[N][i][j]);
    }
  }

  cout << res << endl;

  return 0;
}