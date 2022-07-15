#include <iostream>
#include <vector>

using namespace std;

int solution(int n);

int main() {
  int tCase;

  cin >> tCase;

  for (int i = 0; i < tCase; i++) {
    int n;

    cin >> n;

    cout << solution(n) << endl;
  }

  return 0;
}

int solution(int n) {
  int answer = 0;
  vector<int> dp(n, 0);

  dp[0] = 1;  // 1 = 1;
  dp[1] = 2;  // 2 = 1 + 1, 2;
  dp[2] = 4;  // 3 = 1 + 1 + 1, 1 + 2, 2 + 1, 3;

  for (int i = 3; i < n; i++) {
    dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
  }

  answer = dp[n - 1];

  return answer;
}