#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<int> weight;
int N, res;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  weight = vector<int>(N);
  res = 1;

  for (int i = 0; i < N; i++)
    cin >> weight[i];

  sort(weight.begin(), weight.end());

  for (int i = 0; i < N; i++) {
    if (weight[i] > res)
      break;
    res += weight[i];
  }

  cout << res << endl;

  return 0;
}