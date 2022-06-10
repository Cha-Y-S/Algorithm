#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<vector<int>> matrix;
vector<vector<int>> dp;
int N, M;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

  matrix = vector<vector<int>>(N + 1, vector<int>(M + 1, 0));
  dp = vector<vector<int>>(N + 1, vector<int>(M + 1, 0));

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      cin >> matrix[i][j];
    }
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      dp[i][j] = matrix[i][j] + max({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
    }
  }

  cout << dp[N][M] << endl;

  return 0;
}