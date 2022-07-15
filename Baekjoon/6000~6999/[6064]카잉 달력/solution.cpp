#include <iostream>

using namespace std;

#define endl "\n"

int T, N, M, X, Y;

int gcd(int a, int b);
int lcm(int a, int b);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> T;

  for (; T > 0; T--) {
    cin >> M >> N >> X >> Y;

    int limit = lcm(M, N);

    while (true) {
      if (X > limit || (X - 1) % N + 1 == Y)
        break;

      X += M;
    }

    cout << (X > limit ? -1 : X) << endl;
  }

  return 0;
}

int gcd(int a, int b) {
  return a % b == 0 ? b : gcd(b, a % b);
}

int lcm(int a, int b) {
  return a * b / gcd(a, b);
}