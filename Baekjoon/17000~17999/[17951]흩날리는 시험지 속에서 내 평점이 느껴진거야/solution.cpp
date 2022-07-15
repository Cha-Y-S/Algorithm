#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<int> point;
int N, K, param, lhs, rhs, res;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> K;
  res = param = 0;

  point = vector<int>(N);

  for (int i = 0; i < N; i++) {
    cin >> point[i];

    param += point[i];
  }

  lhs = 0;
  rhs = param;

  while (lhs <= rhs) {
    int mid = (lhs + rhs) / 2;
    int cnt = 0;
    int sum = 0;

    for (int i = 0; i < N; i++) {
      sum += point[i];

      if (sum >= mid) {
        cnt++;
        sum = 0;
      }
    }

    if (cnt >= K) {
      res = mid;
      lhs = mid + 1;
    } else {
      rhs = mid - 1;
    }
  }

  cout << res << endl;

  return 0;
}