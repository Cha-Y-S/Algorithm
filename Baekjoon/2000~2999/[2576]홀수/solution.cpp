#include <iostream>

using namespace std;

#define endl "\n"

int num, res_min, res_sum;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  res_min = 100;
  res_sum = 0;

  for (int i = 0; i < 7; i++) {
    cin >> num;

    if (num % 2 != 0) {
      res_min = res_min > num ? num : res_min;
      res_sum += num;
    }
  }

  if (res_sum == 0) {
    cout << -1 << endl;
  } else {
    cout << res_sum << endl
         << res_min << endl;
  }

  return 0;
}