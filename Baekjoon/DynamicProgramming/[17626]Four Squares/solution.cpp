#include <climits>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<int> dp;
int N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  dp = vector<int>(N + 1, 0);

  dp[1] = 1;

  for (int i = 2; i <= N; i++) {
    int minimum = INT_MAX;
    for (int j = 1; j * j <= i; j++) {
      int temp = i - j * j;
      minimum = minimum < dp[temp] ? minimum : dp[temp];
    }
    dp[i] = minimum + 1;
  }

  cout << dp[N] << endl;

  return 0;
}