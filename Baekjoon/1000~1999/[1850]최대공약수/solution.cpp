#include <iostream>

using namespace std;

#define endl "\n"

int getGCD(long long a, long long b);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  long long a, b;

  cin >> a >> b;

  int gcd = getGCD(a, b);

  for (int i = 0; i < gcd; i++)
    cout << 1;
  cout << endl;

  return 0;
}

int getGCD(long long a, long long b) {
  while (a % b != 0) {
    long long temp = a;
    a = b;
    b = temp % b;
  }
  return b;
}