#include <iostream>
#include <vector>

using namespace std;

vector<int> dp;
vector<int> seq;
int N, res;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  dp = vector<int>(N);
  seq = vector<int>(N);

  for (int i = 0; i < N; i++)
    cin >> seq[i];

  res = dp[0] = seq[0];
  for (int i = 1; i < N; i++) {
    dp[i] = seq[i];
    dp[i] = dp[i] < dp[i - 1] + seq[i] ? dp[i - 1] + seq[i] : dp[i];
    res = res < dp[i] ? dp[i] : res;
  }

  cout << res << endl;

  return 0;
}