#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

vector<pair<int, pii>> dp;
int N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;
  dp = vector<pair<int, pii>>(N + 1, {0, {0, 0}});

  for (int i = 1; i <= N; i++)
    cin >> dp[i].second.first >> dp[i].second.second;

  for (int i = N; i > 0; i--) {
    int next = i + dp[i].second.first;
    if (next > N + 1)
      dp[i].first = dp[i + 1].first;
    else
      dp[i].first = max(dp[i + 1].first, dp[next].first + dp[i].second.second);
  }

  cout << dp[1].first << endl;

  return 0;
}