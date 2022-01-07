#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<vector<int>> matrix;
vector<vector<int>> dp;
int N, M, sx, sy, ex, ey;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

  matrix = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
  dp = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> matrix[i][j];
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + matrix[i][j];
    }
  }

  for (int i = 0; i < M; i++) {
    cin >> sx >> sy >> ex >> ey;

    cout << dp[ex][ey] - dp[sx - 1][ey] - dp[ex][sy - 1] + dp[sx - 1][sy - 1] << endl;
  }

  return 0;
}