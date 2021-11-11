#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

int N, K, res, low, high, mid;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> K;

  low = 1, high = K;

  while (low <= high) {
    int cnt = 0;
    mid = (low + high) / 2;

    for (int i = 1; i <= N; i++)
      cnt += mid / i < N ? mid / i : N;

    if (cnt < K)
      low = mid + 1;
    else {
      res = mid;
      high = mid - 1;
    }
  }

  cout << res << endl;

  return 0;
}
