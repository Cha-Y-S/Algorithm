#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"
#define MOD 1000000000

vector<vector<int>> dp;
int N, res;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  dp = vector<vector<int>>(N + 1, vector<int>(10, 1));

  dp[1][0] = 0;
  res = 0;

  for (int i = 2; i <= N; i++) {
    for (int j = 0; j < 10; j++) {
      if (j == 0)
        dp[i][j] = dp[i - 1][j + 1];
      else if (j == 9)
        dp[i][j] = dp[i - 1][j - 1];
      else
        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];

      dp[i][j] %= MOD;
    }
  }

  for (int i = 0; i < 10; i++)
    res = (res + dp[N][i]) % MOD;

  cout << res << endl;

  return 0;
}