#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"
#define MOD 1000000000

vector<vector<vector<int>>> dp;
int N, res;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  dp = vector<vector<vector<int>>>(N + 1, vector<vector<int>>(10, vector<int>(1 << 10, 0)));
  res = 0;

  for (int i = 1; i < 10; i++)
    dp[1][i][1 << i] = 1;

  for (int i = 2; i <= N; i++) {
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k <= (1 << 10) - 1; k++) {
        if (j == 0)
          dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j + 1][k]) % MOD;
        else if (j == 9)
          dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j - 1][k]) % MOD;
        else {
          dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j - 1][k]) % MOD;
          dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j + 1][k]) % MOD;
        }
      }
    }
  }

  for (int i = 0; i < 10; i++)
    res = (res + dp[N][i][(1 << 10) - 1]) % MOD;

  cout << res << endl;

  return 0;
}