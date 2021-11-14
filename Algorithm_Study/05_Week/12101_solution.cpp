#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> dp;
string res;
int N, K;

void make_expression(int idx, int n, int k);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> K;

  dp = vector<int>(N + 1, 0);
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 4;

  for (int i = 4; i <= N; i++)
    dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

  if (dp[N] < K)
    cout << -1 << endl;
  else {
    make_expression(N - 1, N, K);
    cout << res << endl;
  }

  return 0;
}

void make_expression(int idx, int n, int k) {
  if (n == 1) {
    res += '1';
    return;
  } else if (n == 2 && k == 2) {
    res += '2';
    return;
  } else if (n == 3 && k == 4) {
    res += '3';
    return;
  }

  if (k > dp[idx])
    make_expression(idx - 1, n, k - dp[idx]);
  else {
    res += (n - idx + '0');
    res += '+';
    make_expression(idx - 1, idx, k);
  }
}