#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<int> seq, dp;
int N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  seq = vector<int>(N);
  dp = vector<int>(N);

  for (int i = 0; i < N; i++) {
    cin >> seq[i];
    dp[i] = seq[i];
  }

  for (int i = 1; i < N; i++) {
    for (int j = i - 1; j >= 0; j--) {
      if (seq[i] > seq[j]) {
        dp[i] = max(dp[i], dp[j] + seq[i]);
      }
    }
  }

  cout << *max_element(dp.begin(), dp.end()) << endl;

  return 0;
}