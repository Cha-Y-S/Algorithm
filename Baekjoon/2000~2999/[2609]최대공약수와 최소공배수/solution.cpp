#include <cmath>
#include <iostream>

using namespace std;

#define endl "\n"

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int a, b, gcd;

  cin >> a >> b;

  int lcm = a * b;

  while (a % b != 0) {
    int swap = a;
    a = b;
    b = swap % b;
  }

  gcd = b;

  lcm /= gcd;

  cout << gcd << endl;
  cout << lcm << endl;

  return 0;
}