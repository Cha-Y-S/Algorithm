#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> seq);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;

  cin >> n;

  vector<int> seq(n, 0);

  for (int i = 0; i < n; i++) {
    cin >> seq[i];
  }

  cout << solution(seq) << endl;

  return 0;
}

int solution(vector<int> seq) {
  int answer = 0;
  vector<int> dp(seq.size(), 1);

  for (int i = 1; i < seq.size(); i++) {
    for (int j = i - 1; j >= 0; j--) {
      if (seq[i] > seq[j]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }

  answer = *max_element(dp.begin(), dp.end());

  return answer;
}