#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> boxes;
int T, J, N, R, C, res;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> T;

  for (; T > 0; T--) {
    cin >> J >> N;

    boxes = vector<int>(N);
    res = 0;

    for (int i = 0; i < N; i++) {
      cin >> R >> C;

      boxes[i] = R * C;
    }

    sort(boxes.begin(), boxes.end(), greater<>());

    for (int i = 0; i < N; i++) {
      J -= boxes[i];
      res++;
      if (J <= 0) break;
    }

    cout << res << endl;
  }

  return 0;
}