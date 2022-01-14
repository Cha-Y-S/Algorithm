#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"
#define MOD 9901

vector<vector<int>> dp;
int N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  dp = vector<vector<int>>(N + 1, vector<int>(3, 1));

  for (int i = 2; i <= N; i++) {
    dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % MOD;
    dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
    dp[i][2] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % MOD;
  }

  cout << (dp[N][0] + dp[N][1] + dp[N][2]) % MOD << endl;

  return 0;
}