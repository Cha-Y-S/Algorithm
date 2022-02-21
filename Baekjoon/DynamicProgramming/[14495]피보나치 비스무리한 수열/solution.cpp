#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"
#define MAX 117

typedef long long ll;

vector<ll> dp;
int N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  dp = vector<ll>(MAX);

  dp[1] = dp[2] = dp[3] = 1;

  for (int i = 4; i <= N; i++)
    dp[i] = dp[i - 1] + dp[i - 3];

  cout << dp[N] << endl;

  return 0;
}