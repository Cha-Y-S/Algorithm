#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<int> seq, dp, lis;
int N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  seq = vector<int>(N);
  dp = vector<int>(N, 1);

  for (int i = 0; i < N; i++) {
    cin >> seq[i];
  }

  for (int i = 1; i < N; i++) {
    for (int j = i - 1; j >= 0; j--) {
      if (seq[i] > seq[j]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }

  int target = *max_element(dp.begin(), dp.end());

  lis = vector<int>(target);

  for (int i = N - 1; i >= 0; i--) {
    if (dp[i] == target) {
      lis[target - 1] = seq[i];
      target--;
    }
  }

  cout << lis.size() << endl;

  for (int i = 0; i < lis.size(); i++) {
    cout << lis[i] << " ";
  }
  cout << endl;

  return 0;
}