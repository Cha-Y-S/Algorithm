#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<int> seq;
vector<vector<int>> dp;
int N, res;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  seq = vector<int>(N);
  dp = vector<vector<int>>(N, vector<int>(2));

  for (int i = 0; i < N; i++)
    cin >> seq[i];

  res = seq[0];

  for (int i = 0; i < N; i++) {
    dp[i][0] = dp[i][1] = seq[i];
    if (i == 0) continue;
    dp[i][0] = max(dp[i - 1][0] + seq[i], seq[i]);
    dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + seq[i]);
    res = max(res, max(dp[i][0], dp[i][1]));
  }

  cout << res << endl;

  return 0;
}