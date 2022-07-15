#include <iostream>
#include <vector>

using namespace std;

pair<int, int> solution(int n);

int main() {
  int t;

  cin >> t;

  for (int i = 0; i < t; i++) {
    int n;

    cin >> n;

    pair<int, int> answer;

    answer = solution(n);

    cout << answer.first << " " << answer.second << endl;
  }

  return 0;
}

pair<int, int> solution(int n) {
  pair<int, int> answer;

  vector<pair<int, int>> dp;

  dp.push_back(make_pair(1, 0));
  dp.push_back(make_pair(0, 1));

  for (int i = 2; i <= n; i++) {
    dp.push_back(make_pair(dp[i - 2].first + dp[i - 1].first, dp[i - 2].second + dp[i - 1].second));
  }

  answer = dp[n];

  return answer;
}