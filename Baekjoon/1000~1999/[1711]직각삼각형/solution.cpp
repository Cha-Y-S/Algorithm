#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define endl "\n"

typedef long long ll;
typedef pair<ll, ll> pll;

vector<pll> loc, tmp;
map<pll, int> m;
ll X, Y, res;
int N;

ll gcd(ll a, ll b) {
  if (!b) return a;
  return gcd(b, a % b);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  loc = vector<pll>(N);
  res = 0;

  for (int i = 0; i < N; i++) {
    cin >> X >> Y;

    loc[i] = {X, Y};
  }

  for (int i = 0; i < N; i++) {
    tmp = loc;
    swap(tmp[0], tmp[i]);

    for (int j = 1; j < N; j++) {
      ll x = tmp[j].first - tmp[0].first;
      ll y = tmp[j].second - tmp[0].second;
      ll g = gcd(x, y);

      if (g < 0) g = -g;

      x /= g;
      y /= g;

      m[{x, y}]++;
    }

    for (pair<pll, int> p : m) {
      ll cx = p.first.first;
      ll cy = p.first.second;

      if (m.find({-cy, cx}) != m.end()) {
        res += p.second * m[{-cy, cx}];
      }
    }

    m.clear();
  }

  cout << res << endl;

  return 0;
}