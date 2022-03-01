#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"
#define MAX 100'001

vector<int> dp;
int N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  dp = vector<int>(MAX, 0);

  dp[1] = dp[2] = dp[5] = dp[7] = 1;
  dp[3] = dp[4] = dp[6] = 2;

  for (int i = 8; i <= N; i++)
    dp[i] = min({dp[i - 1] + 1, dp[i - 2] + 1, dp[i - 5] + 1, dp[i - 7] + 1});

  cout << dp[N] << endl;

  return 0;
}