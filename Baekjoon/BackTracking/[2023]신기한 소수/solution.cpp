#include <iostream>

using namespace std;

#define endl "\n"

int N;

void make_prime(int p, int cnt);
bool isPrime(int n);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  make_prime(0, 0);

  return 0;
}

bool isPrime(int n) {
  if (n == 1) return false;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0)
      return false;
  }
  return true;
}

void make_prime(int p, int cnt) {
  if (cnt == N) {
    cout << p << endl;
    return;
  }

  p *= 10;

  for (int i = 1; i < 10; i++) {
    p += i;
    if (isPrime(p))
      make_prime(p, cnt + 1);
    p -= i;
  }
}