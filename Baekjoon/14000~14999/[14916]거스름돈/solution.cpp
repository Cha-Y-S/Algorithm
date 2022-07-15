#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"
#define MAX_SIZE 100'001
#define MAX_VALUE 50'001
#define MIN(X, Y) (X > Y ? Y : X)

vector<int> dp;
int N;

int solution(int n);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  dp = vector<int>(MAX_SIZE, MAX_VALUE);

  dp[1] = MAX_VALUE;
  dp[2] = 1;
  dp[3] = MAX_VALUE;
  dp[4] = 2;
  dp[5] = 1;

  for (int i = 6; i <= N; i++)
    dp[i] = MIN(dp[i - 2] + 1, dp[i - 5] + 1);

  cout << (dp[N] >= MAX_VALUE ? -1 : dp[N]) << endl;

  return 0;
}