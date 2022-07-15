#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"
#define MAX(X, Y) (X > Y ? X : Y)
#define BENEFIT_A(X) (int)(X * 1.05)
#define BENEFIT_B(X) (int)(X * 1.2)
#define BENEFIT_C(X) (int)(X * 1.35)

vector<int> dp;
int H, Y;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> H >> Y;

  dp = vector<int>(Y + 1);
  dp[0] = H;

  for (int i = 1; i <= Y; i++) {
    if (i >= 5)
      dp[i] = MAX(BENEFIT_A(dp[i - 1]), MAX(BENEFIT_B(dp[i - 3]), BENEFIT_C(dp[i - 5])));
    else if (i >= 3)
      dp[i] = MAX(BENEFIT_A(dp[i - 1]), BENEFIT_B(dp[i - 3]));
    else
      dp[i] = BENEFIT_A(dp[i - 1]);
  }

  cout << dp[Y] << endl;

  return 0;
}