#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<int> seq, lis;
int T, N, res;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> T;

  for (int t = 0; t < T; t++) {
    cin >> N;

    seq = vector<int>(N);
    res = 0;

    for (int i = 0; i < N; i++) {
      cin >> seq[i];
    }

    for (int i = 0; i < N; i++) {
      lis.clear();

      for (int j = i; j < N; j++) {
        int idx = lower_bound(lis.begin(), lis.end(), seq[j]) - lis.begin();

        if (idx == lis.size()) {
          lis.push_back(seq[j]);
        } else {
          lis[idx] = seq[j];
        }

        res += lis.size();
      }
    }

    cout << "Case #" << t + 1 << ": " << res << endl;
  }

  return 0;
}