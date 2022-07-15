#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> stair);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;

  cin >> n;

  vector<int> stair(n, 0);

  for (int i = 0; i < n; i++) {
    cin >> stair[i];
  }

  cout << solution(stair) << endl;

  return 0;
}

int solution(vector<int> stair) {
  int answer = 0;
  vector<int> dp;

  dp.push_back(stair[0]);

  if (stair.size() < 2) return answer = dp[0];
  dp.push_back(stair[0] + stair[1]);

  if (stair.size() < 3) return answer = dp[1];
  dp.push_back(max(stair[0] + stair[2], stair[1] + stair[2]));

  if (stair.size() < 4) return answer = dp[2];

  for (int i = 3; i < stair.size(); i++) {
    dp.push_back(max(stair[i] + dp[i - 2], stair[i] + stair[i - 1] + dp[i - 3]));
  }

  answer = dp[stair.size() - 1];

  return answer;
}