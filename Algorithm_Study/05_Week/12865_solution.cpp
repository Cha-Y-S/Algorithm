#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<int, int> pii;

vector<vector<int>> dp;
vector<pii> objects;
int N, K, res;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> K;

  objects = vector<pii>(N + 1);
  dp = vector<vector<int>>(N + 1, vector<int>(K + 1, 0));
  res = 0;

  for (int i = 1; i <= N; i++)
    cin >> objects[i].first >> objects[i].second;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= K; j++) {
      if (objects[i].first <= j) {
        dp[i][j] = max(objects[i].second + dp[i - 1][j - objects[i].first], dp[i - 1][j]);
      } else
        dp[i][j] = dp[i - 1][j];

      res = max(dp[i][j], res);
    }
  }

  cout << res << endl;

  return 0;
}