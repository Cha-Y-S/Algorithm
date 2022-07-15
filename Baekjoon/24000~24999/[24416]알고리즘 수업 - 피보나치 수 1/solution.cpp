#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<int> dp;
int N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  dp = vector<int>(N + 1);

  dp[1] = 1;
  dp[2] = 1;

  for (int i = 3; i <= N; i++)
    dp[i] = dp[i - 1] + dp[i - 2];

  cout << dp[N] << " " << N - 2 << endl;

  return 0;
}