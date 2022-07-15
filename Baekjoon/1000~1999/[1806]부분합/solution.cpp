#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<int> seq;
int N, S, l_idx, r_idx, sum, res;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> S;
  seq = vector<int>(N);
  res = N + 1;
  l_idx = r_idx = 0;

  for (int i = 0; i < N; i++)
    cin >> seq[i];
  sum = seq[0];

  while (l_idx <= r_idx && r_idx < N) {
    if (sum < S) {
      r_idx++;
      sum += seq[r_idx];
    } else {
      res = r_idx - l_idx + 1 > res ? res : r_idx - l_idx + 1;
      sum -= seq[l_idx++];

      if (l_idx > r_idx) {
        r_idx = l_idx;
        sum = seq[l_idx];
      }
    }
  }

  cout << (res == N + 1 ? 0 : res) << endl;

  return 0;
}