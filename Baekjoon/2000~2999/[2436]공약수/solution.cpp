#include <iostream>

using namespace std;

#define endl "\n"

typedef long long ll;

ll getGCD(ll a, ll b);
ll getLCM(ll a, ll b, ll gcd);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  pair<ll, ll> n;
  ll gcd, lcm;

  cin >> gcd >> lcm;

  n.first = gcd;
  n.second = lcm;

  ll mult = gcd * lcm;

  for (ll i = gcd + 1; i * i < mult; i++) {
    if (mult % i == 0) {
      ll n1 = i;
      ll n2 = mult / i;

      ll t_gcd = getGCD(n1, n2);
      ll t_lcm = getLCM(n1, n2, t_gcd);

      if (t_gcd == gcd && t_lcm == lcm)
        n = n.first + n.second > n1 + n2 ? make_pair(n1, n2) : n;
    }
  }

  cout << n.first << " " << n.second << endl;

  return 0;
}

ll getGCD(ll a, ll b) {
  while (a % b != 0) {
    int temp = a;
    a = b;
    b = temp % b;
  }
  return b;
}

ll getLCM(ll a, ll b, ll gcd) {
  return (a * b) / gcd;
}