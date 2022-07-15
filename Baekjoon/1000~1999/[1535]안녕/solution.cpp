#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"
#define MAX(X, Y) (X > Y ? X : Y)

using namespace std;

vector<int> hp, happy, dp;
int N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  hp = vector<int>(N, 0);
  happy = vector<int>(N, 0);
  dp = vector<int>(101, 0);

  for (int i = 0; i < N; i++) {
    cin >> hp[i];
  }

  for (int i = 0; i < N; i++) {
    cin >> happy[i];
  }

  for (int i = 0; i < N; i++) {
    for (int j = 100; j >= hp[i]; j--) {
      dp[j] = max(dp[j], dp[j - hp[i]] + happy[i]);
    }
  }

  cout << dp[99] << endl;

  return 0;
}