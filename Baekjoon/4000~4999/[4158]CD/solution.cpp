#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<int> CD;
int N, M, num, res;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  while (true) {
    cin >> N >> M;

    if (N == 0 && M == 0) break;

    if (N == 0 || M == 0) {
      cout << 0 << endl;
      continue;
    }

    res = 0;

    CD = vector<int>(N);

    for (int i = 0; i < N; i++) {
      cin >> CD[i];
    }

    for (int i = 0; i < M; i++) {
      cin >> num;

      if (num == *lower_bound(CD.begin(), CD.end(), num)) res++;
    }

    cout << res << endl;
  }

  return 0;
}