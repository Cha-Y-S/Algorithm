#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int n);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;

  cin >> n;

  while (n > 1) {
    for (int i = 2; i <= sqrt(n); i++) {
      if (isPrime(i) && (n % i == 0)) {
        cout << i << endl;
        n /= i;
        break;
      }
    }

    if (isPrime(n)) {
      cout << n << endl;
      n /= n;
    }
  }

  return 0;
}

bool isPrime(int n) {
  if (n == 2)
    return true;
  else if (n == 3)
    return true;

  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0)
      return false;
  }

  return true;
}