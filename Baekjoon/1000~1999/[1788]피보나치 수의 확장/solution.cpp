#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"
#define MAX 1'000'001
#define MOD 1'000'000'000

vector<int> dp;
int N, tmp;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  dp = vector<int>(MAX, 0);
  tmp = abs(N);
  dp[1] = 1;

  for (int i = 2; i <= tmp; i++)
    dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;

  cout << (N == 0 ? 0 : (N < 0 && tmp % 2 == 0 ? -1 : 1)) << endl;
  cout << abs(dp[tmp]) << endl;

  return 0;
}