#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"
#define MAX(X, Y) (X > Y ? X : Y)

vector<vector<int>> sticker;
vector<vector<int>> dp;
int T, N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> T;

  while (T--) {
    cin >> N;

    sticker = vector<vector<int>>(2, vector<int>(N));
    dp = vector<vector<int>>(2, vector<int>(N + 1));

    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < N; j++) {
        cin >> sticker[i][j];
      }
    }

    dp[0][0] = sticker[0][0];
    dp[1][0] = sticker[1][0];

    if (N > 1) {
      dp[0][1] = sticker[0][1] + dp[1][0];
      dp[1][1] = sticker[1][1] + dp[0][0];
    }

    for (int i = 2; i < N; i++) {
      dp[0][i] = sticker[0][i] + MAX(dp[1][i - 1], dp[1][i - 2]);
      dp[1][i] = sticker[1][i] + MAX(dp[0][i - 1], dp[0][i - 2]);
    }

    cout << MAX(dp[0][N - 1], dp[1][N - 1]) << endl;
  }

  return 0;
}