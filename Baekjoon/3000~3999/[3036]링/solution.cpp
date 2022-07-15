#include <iostream>

using namespace std;

#define endl "\n"

int getGCD(int a, int b);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, object, target, gcd;

  cin >> n >> object;

  for (int i = 0; i < n - 1; i++) {
    cin >> target;

    gcd = getGCD(object, target);

    cout << object / gcd << "/" << target / gcd << endl;
  }

  return 0;
}

int getGCD(int a, int b) {
  while (a % b != 0) {
    int temp = a;
    a = b;
    b = temp % b;
  }

  return b;
}