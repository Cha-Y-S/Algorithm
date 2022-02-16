#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<vector<int>> dp;
int N, K;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> K;

  dp = vector<vector<int>>(N);

  for (int i = 0; i < N; i++) {
    dp[i] = vector<int>(i + 1);

    for (int j = 0; j < dp[i].size(); j++) {
      if (j == 0) {
        dp[i][j] = 1;
        continue;
      }
      if (j == dp[i].size() - 1) {
        dp[i][j] = 1;
        break;
      }
      dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
    }
  }

  cout << dp[N - 1][K - 1] << endl;

  return 0;
}