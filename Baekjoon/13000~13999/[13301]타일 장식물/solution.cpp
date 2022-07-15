#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<long long> dp;
int N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  dp = vector<long long>(N + 1);

  switch (N) {
    case 1:
      cout << 4 << endl;
      break;
    case 2:
      cout << 6 << endl;
      break;
    default:
      dp[1] = 4;
      dp[2] = 6;
      for (int i = 3; i <= N; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

      cout << dp[N] << endl;
      break;
  }

  return 0;
}