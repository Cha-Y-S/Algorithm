#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"
#define MAX 1001

vector<int> dp;
int N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  dp = vector<int>(MAX);

  dp[1] = dp[3] = 0;
  dp[2] = dp[4] = 1;

  for (int i = 5; i <= N; i++) {
    if (min({dp[i - 1], dp[i - 3], dp[i - 4]}) == 1)
      dp[i] = 0;
    else
      dp[i] = 1;
  }

  cout << (dp[N] == 1 ? "SK" : "CY") << endl;

  return 0;
}