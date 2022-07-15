#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"
#define MAX(X, Y) (X > Y ? X : Y)

vector<double> dp;
double res;
int N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  dp = vector<double>(N);

  for (int i = 0; i < N; i++)
    cin >> dp[i];

  res = dp[0];

  for (int i = 1; i < N; i++) {
    dp[i] = MAX(dp[i], dp[i - 1] * dp[i]);
    res = MAX(res, dp[i]);
  }

  cout << fixed;
  cout.precision(3);
  cout << res << endl;

  return 0;
}