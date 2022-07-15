#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;

  cin >> n;

  vector<int> dp(n + 1, 0);

  for (int i = 2; i <= n; i++) {
    dp[i] = dp[i - 1] + 1;
    dp[i] = i % 2 == 0 ? min(dp[i], dp[i / 2] + 1) : dp[i];
    dp[i] = i % 3 == 0 ? min(dp[i], dp[i / 3] + 1) : dp[i];
  }

  cout << dp[n] << endl;

  return 0;
}