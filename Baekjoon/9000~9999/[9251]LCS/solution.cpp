#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define endl "\n"

vector<vector<int>> dp;
string A, B;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> A;
  cin >> B;

  dp = vector<vector<int>>(A.size() + 1, vector<int>(B.size() + 1));

  for (int i = 0; i < dp.size(); i++) {
    for (int j = 0; j < dp[i].size(); j++) {
      if (i == 0 || j == 0) {
        dp[i][j] = 0;
      } else if (A[i - 1] == B[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  cout << dp[A.size()][B.size()] << endl;

  return 0;
}
