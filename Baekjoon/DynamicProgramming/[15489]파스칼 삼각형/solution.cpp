#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<vector<int>> dp;
int R, C, W;
long long res;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  dp = vector<vector<int>>(30);
  res = 0;

  for (int i = 0; i < 30; i++) {
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

  cin >> R >> C >> W;

  for (int i = R - 1; i < R + W - 1; i++) {
    for (int j = C - 1; j < C + i - R + 1; j++)
      res += dp[i][j];
  }

  cout << res << endl;

  return 0;
}