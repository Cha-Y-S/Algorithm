#include <iostream>
#include <vector>

#define endl "\n"

using namespace std;

typedef pair<int, int> pii;

vector<pii> dp;
int N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  dp = vector<pii>(N + 3, {0, 0});

  dp[1] = {0, 0};
  dp[2] = {1, 1};
  dp[3] = {1, 1};

  for (int i = 4; i <= N; i++) {
    dp[i] = {dp[i - 1].first + 1, i - 1};

    if (i % 2 == 0) {
      if (dp[i].first > dp[i / 2].first + 1) {
        dp[i] = {dp[i / 2].first + 1, i / 2};
      }
    }

    if (i % 3 == 0) {
      if (dp[i].first > dp[i / 3].first + 1) {
        dp[i] = {dp[i / 3].first + 1, i / 3};
      }
    }
  }

  cout << dp[N].first << endl;

  int idx = N;
  while (idx > 0) {
    cout << idx << " ";

    idx = dp[idx].second;
  }

  cout << endl;

  return 0;
}