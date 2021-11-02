#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<int> seq;
int N, M, l_idx, r_idx, sum, res;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

  seq = vector<int>(N);
  res = l_idx = r_idx = 0;

  for (int i = 0; i < N; i++)
    cin >> seq[i];

  sum = seq[0];

  while (l_idx <= r_idx && r_idx < N) {
    if (sum < M) {
      r_idx++;
      sum += seq[r_idx];
    } else if (sum > M) {
      sum -= seq[l_idx++];

      if (l_idx > r_idx) {
        r_idx = l_idx;
        sum = seq[l_idx];
      }
    } else {
      res++;
      sum += seq[++r_idx];
    }
  }

  cout << res << endl;

  return 0;
}