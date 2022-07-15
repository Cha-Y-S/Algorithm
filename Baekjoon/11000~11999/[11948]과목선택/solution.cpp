#include <iostream>

using namespace std;

#define endl "\n"

int point, low, res;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  low = 100;
  res = 0;

  for (int i = 0; i < 4; i++) {
    cin >> point;

    low = low > point ? point : low;

    res += point;
  }

  res -= low;
  low = 100;

  for (int i = 0; i < 2; i++) {
    cin >> point;

    low = low > point ? point : low;

    res += point;
  }

  res -= low;

  cout << res << endl;

  return 0;
}