#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"
#define MAX 51
#define MOD 1'000'000'007

vector<int> dp;
int N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  dp = vector<int>(MAX);

  dp[0] = 1;
  dp[1] = 1;

  for (int i = 2; i <= N; i++)
    dp[i] = (dp[i - 1] + dp[i - 2] + 1) % MOD;

  cout << dp[N] << endl;

  return 0;
}