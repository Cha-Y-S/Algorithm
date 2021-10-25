#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

typedef long long ll;

vector<ll> dp;
vector<int> input;
int T, N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> T;

  input = vector<int>(T);

  for (int i = 0; i < T; i++)
    cin >> input[i];

  N = *max_element(input.begin(), input.end());

  dp = vector<ll>(N);

  dp = {0, 1, 1, 1, 2, 2};

  for (int i = 6; i <= N; i++)
    dp[i] = dp[i - 5] + dp[i - 1];

  for (int i = 0; i < input.size(); i++)
    cout << dp[input[i]] << endl;

  return 0;
}