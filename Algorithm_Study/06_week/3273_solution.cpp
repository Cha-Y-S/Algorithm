#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<int> seq;
int N, X, l_idx, r_idx, sum, res;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  seq = vector<int>(N);
  l_idx = 0;
  r_idx = N - 1;
  res = 0;

  for (int i = 0; i < N; i++)
    cin >> seq[i];

  cin >> X;

  sort(seq.begin(), seq.end());

  while (l_idx < r_idx) {
    sum = seq[l_idx] + seq[r_idx];

    if (sum < X)
      l_idx++;
    else if (sum > X)
      r_idx--;
    else {
      res++;
      l_idx++;
    }
  }

  cout << res << endl;

  return 0;
}