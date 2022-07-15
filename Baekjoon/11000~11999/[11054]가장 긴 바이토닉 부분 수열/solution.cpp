#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> seq, rseq, dp_asc, dp_desc;
int N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  seq = vector<int>(N);
  rseq = vector<int>(N);
  dp_asc = vector<int>(N, 1);
  dp_desc = vector<int>(N, 1);

  for (int i = 0; i < N; i++) {
    cin >> seq[i];
    rseq[i] = seq[i];
  }

  reverse(rseq.begin(), rseq.end());

  for (int i = 1; i < N; i++) {
    for (int j = i - 1; j >= 0; j--) {
      if (seq[i] > seq[j]) {
        dp_asc[i] = max(dp_asc[i], dp_asc[j] + 1);
      }
      if (rseq[i] > rseq[j]) {
        dp_desc[i] = max(dp_desc[i], dp_desc[j] + 1);
      }
    }
  }

  int lbs_size = 0;

  for (int i = 0; i < N; i++) {
    lbs_size = max(lbs_size, dp_asc[i] + dp_desc[N - i - 1] - 1);
  }

  cout << lbs_size << endl;

  return 0;
}