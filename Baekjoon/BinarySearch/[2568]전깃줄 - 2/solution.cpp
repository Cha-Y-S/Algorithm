#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<int, int> pii;

vector<pii> pole;
vector<int> lis, idxs, res;
int N, A, B;

int cmp(pii a, pii b);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  pole = vector<pii>(N);
  idxs = vector<int>(N);

  for (int i = 0; i < N; i++) {
    cin >> A >> B;

    pole[i] = {A, B};
  }

  sort(pole.begin(), pole.end(), cmp);

  for (int i = 0; i < N; i++) {
    int idx = lower_bound(lis.begin(), lis.end(), pole[i].second) - lis.begin();

    idxs[i] = idx;

    if (idx == lis.size()) {
      lis.push_back(pole[i].second);
    } else {
      lis[idx] = pole[i].second;
    }
  }

  int target = lis.size() - 1;

  for (int i = N - 1; i >= 0; i--) {
    if (target == idxs[i]) {
      target--;
    } else {
      res.push_back(pole[i].first);
    }
  }

  sort(res.begin(), res.end());

  cout << N - lis.size() << endl;

  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << endl;
  }

  return 0;
}

int cmp(pii a, pii b) {
  return a.first < b.first;
}