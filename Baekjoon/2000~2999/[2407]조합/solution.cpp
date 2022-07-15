#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define endl "\n"

vector<vector<string>> dp;
int N, M;

string addNumber(string a, string b);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

  dp = vector<vector<string>>(N + 1);

  for (int i = 0; i <= N; i++) {
    dp[i] = vector<string>(i + 1);
  }

  dp[0][0] = dp[1][0] = dp[1][1] = "1";

  for (int i = 2; i <= N; i++) {
    for (int j = 0; j < dp[i].size(); j++) {
      if (i == j || j == 0) {
        dp[i][j] = "1";
        continue;
      }
      dp[i][j] = addNumber(dp[i - 1][j - 1], dp[i - 1][j]);
    }
  }

  cout << dp[N][M] << endl;

  return 0;
}

string addNumber(string a, string b) {
  string res = "";

  if (a.size() != b.size()) {
    while (a.size() > b.size()) {
      b = "0" + b;
    }
    while (b.size() > a.size()) {
      a = "0" + a;
    }
  }

  bool carry = false;

  for (int i = a.size() - 1; i >= 0; i--) {
    int sum = (a[i] - '0') + (b[i] - '0') + (carry ? 1 : 0);
    carry = false;

    res = to_string(sum % 10) + res;

    if (sum >= 10) {
      carry = true;
    }
  }

  if (carry) res = "1" + res;

  return res;
}