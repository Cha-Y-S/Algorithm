#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"
#define MAX 11

vector<int> dp;
int N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  dp = vector<int>(MAX, 0);

  dp[1] = 0;
  dp[2] = 1;
  dp[3] = 3;

  for (int i = 4; i <= N; i++) {
    int a = i / 2;
    int b = i - (i / 2);

    dp[i] = a * b + dp[a] + dp[b];
  }

  cout << dp[N] << endl;

  return 0;
}