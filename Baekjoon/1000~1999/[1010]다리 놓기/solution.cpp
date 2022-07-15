#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"
#define MAX 31

vector<vector<int>> dp;
int T, N, M;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  dp = vector<vector<int>>(MAX, vector<int>(MAX, 0));

  for (int i = 1; i < MAX; i++)
    dp[i][i] = 1;

  for (int i = 2; i < MAX; i++)
    dp[1][i] = i;

  for (int i = 2; i < MAX; i++) {
    for (int j = i + 1; j < MAX; j++) {
      int memo = 0;
      for (int k = i - 1; k < j; k++) {
        memo += dp[i - 1][k];
      }
      dp[i][j] = memo;
    }
  }

  /*
  for (int i = 2; i < MAX; i++) {
    for (int j = 2; j < MAX; j++) {
      dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
    }
  }
  */

  cin >> T;

  for (; T > 0; T--) {
    cin >> N >> M;

    cout << dp[N][M] << endl;
  }

  return 0;
}