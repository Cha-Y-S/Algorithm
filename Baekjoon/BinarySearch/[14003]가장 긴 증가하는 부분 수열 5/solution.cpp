#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<int> A, lis, seq, res;
int N, num;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  A = vector<int>(N);

  for (int i = 0; i < N; i++) {
    cin >> num;

    A[i] = num;

    int idx = lower_bound(lis.begin(), lis.end(), num) - lis.begin();

    if (idx == lis.size()) {
      lis.push_back(num);
    } else {
      lis[idx] = num;
    }

    seq.push_back(idx);
  }

  int target = lis.size() - 1;

  res = vector<int>(lis.size());

  for (int i = seq.size() - 1; i >= 0; i--) {
    if (seq[i] == target) {
      res[seq[i]] = A[i];
      target--;
    }
  }

  cout << res.size() << endl;

  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
  cout << endl;

  return 0;
}