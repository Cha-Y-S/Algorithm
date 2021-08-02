#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> wine);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;

  cin >> n;

  vector<int> wine(n, 0);

  for (int i = 0; i < n; i++) {
    cin >> wine[i];
  }

  // vector<int> wine = {6, 10, 13, 9, 8, 1};

  cout << solution(wine) << endl;

  return 0;
}

int solution(vector<int> wine) {
  int answer = 0;
  vector<int> dp;

  dp.push_back(wine[0]);
  if (wine.size() < 2) return answer = dp[0];

  dp.push_back(wine[0] + wine[1]);
  if (wine.size() < 3) return answer = dp[1];

  dp.push_back(max(wine[0] + wine[1], max(wine[0] + wine[2], wine[1] + wine[2])));
  if (wine.size() < 4) return answer = dp[2];

  for (int i = 3; i < wine.size(); i++) {
    dp.push_back(max(wine[i] + dp[i - 2], max(wine[i] + wine[i - 1] + dp[i - 3], dp[i - 1])));
  }

  answer = dp[wine.size() - 1];

  return answer;
}