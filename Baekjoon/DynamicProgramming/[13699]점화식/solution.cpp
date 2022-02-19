#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

typedef long long ll;

vector<ll> dp;
int N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  dp = vector<ll>(N + 1, 0);
  dp[0] = 1;

  for (int i = 1; i <= N; i++) {
    for (int j = 0; j < i; j++)
      dp[i] += dp[j] * dp[i - j - 1];
  }

  cout << dp[N] << endl;

  return 0;
}