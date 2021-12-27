#include <iostream>

using namespace std;

#define endl "\n"

typedef long long ll;

ll A, B, C;

ll power(ll x, ll n);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> A >> B >> C;

  cout << power(A, B) % C << endl;

  return 0;
}

ll power(ll x, ll n) {
  if (n == 0)
    return 1;
  else if (n == 1)
    return x;

  if (n % 2 != 0)
    return ((power(x, n - 1) % C) * (x % C)) % C;

  ll divide = power(x, n / 2) % C;

  return (divide * divide) % C;
}