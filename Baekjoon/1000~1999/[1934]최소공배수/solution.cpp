#include <iostream>

using namespace std;

#define endl "\n"

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t, a, b;

  cin >> t;

  for (; t > 0; t--) {
    int gcd, lcm;

    cin >> a >> b;

    if (a < b) {
      int temp = a;
      a = b;
      b = temp;
    }

    lcm = a * b;

    while (a % b != 0) {
      int temp = a;
      a = b;
      b = temp % b;
    }

    gcd = b;

    lcm /= gcd;

    cout << lcm << endl;
  }

  return 0;
}