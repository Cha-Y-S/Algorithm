#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"
#define MOD 10007

vector<int> dp;
int N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  dp = vector<int>(N + 1, 1);

  for (int i = 2; i <= N; i++) {
    if (i % 2 == 0)
      dp[i] = (dp[i - 1] * 2 + 1) % MOD;
    else
      dp[i] = (dp[i - 1] * 2 - 1) % MOD;
  }

  cout << dp[N] << endl;

  return 0;
}