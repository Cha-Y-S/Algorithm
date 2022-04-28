#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<int> switchs, lights, seq, lis, idxs, res;
int N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  switchs = vector<int>(N);
  lights = vector<int>(N);

  for (int i = 0; i < N; i++) {
    cin >> switchs[i];
  }

  for (int i = 0; i < N; i++) {
    cin >> lights[i];
  }

  for (int i = 0; i < N; i++) {
    seq.push_back(find(lights.begin(), lights.end(), switchs[i]) - lights.begin());
  }

  for (int i = 0; i < N; i++) {
    int idx = lower_bound(lis.begin(), lis.end(), seq[i]) - lis.begin();

    idxs.push_back(idx);

    if (idx == lis.size()) {
      lis.push_back(seq[i]);
    } else {
      lis[idx] = seq[i];
    }
  }

  int target = lis.size() - 1;

  for (int i = N - 1; i >= 0; i--) {
    if (idxs[i] == target) {
      res.push_back(switchs[i]);
      target--;
    }
  }

  sort(res.begin(), res.end());

  cout << res.size() << endl;
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
  cout << endl;

  return 0;
}