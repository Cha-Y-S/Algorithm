#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<double, int> pdi;

vector<pdi> monitor;
int N, W, H;

int cmp(pdi a, pdi b);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  monitor = vector<pdi>(N);

  for (int i = 0; i < N; i++) {
    cin >> W >> H;

    double ppi = sqrt(W * W + H * H) / 77;

    monitor[i] = {ppi, i + 1};
  }

  sort(monitor.begin(), monitor.end(), cmp);

  for (int i = 0; i < N; i++) {
    cout << monitor[i].second << endl;
  }

  return 0;
}

int cmp(pdi a, pdi b) {
  if (a.first != b.first) {
    return a.first > b.first;
  } else {
    return a.second < b.second;
  }
}