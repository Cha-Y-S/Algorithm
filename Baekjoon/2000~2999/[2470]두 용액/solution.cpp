#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<int> liquid;
pair<int, int> res;
int N, l_idx, r_idx, sum, s_min;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  liquid = vector<int>(N);
  l_idx = 0;
  r_idx = N - 1;
  s_min = INT_MAX;

  for (int i = 0; i < N; i++) cin >> liquid[i];

  sort(liquid.begin(), liquid.end());

  while (l_idx < r_idx) {
    sum = liquid[l_idx] + liquid[r_idx];

    if (s_min > abs(sum)) {
      s_min = abs(sum);
      res = {liquid[l_idx], liquid[r_idx]};
    }

    if (sum < 0)
      l_idx++;
    else if (sum > 0)
      r_idx--;
    else
      break;
  }

  cout << res.first << " " << res.second << endl;

  return 0;
}
