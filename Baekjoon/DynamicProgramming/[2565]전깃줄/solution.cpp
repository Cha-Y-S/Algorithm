#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<int, int> pii;

vector<pii> pole;
vector<int> dp;
int N;

int cmp(pii a, pii b);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  pole = vector<pii>(N);
  dp = vector<int>(N, 1);

  for (int i = 0; i < N; i++) {
    cin >> pole[i].first >> pole[i].second;
  }

  sort(pole.begin(), pole.end(), cmp);

  for (int i = 1; i < N; i++) {
    for (int j = i - 1; j >= 0; j--) {
      if (pole[i].second > pole[j].second) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }

  cout << N - *max_element(dp.begin(), dp.end()) << endl;

  return 0;
}

int cmp(pii a, pii b) {
  return a.first < b.first;
}