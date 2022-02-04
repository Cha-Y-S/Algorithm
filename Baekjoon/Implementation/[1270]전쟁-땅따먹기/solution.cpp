#include <iostream>
#include <map>

using namespace std;

#define endl "\n"

typedef long long ll;

int N, T;
ll n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  for (int i = 0; i < N; i++) {
    map<ll, int> m;
    ll cnt = 0, res = -1;

    cin >> T;

    for (int j = 0; j < T; j++) {
      cin >> n;

      ll tmp = ++m[n];

      if (tmp > cnt) {
        res = n;
        cnt = tmp;
      }
    }

    if (cnt > T / 2)
      cout << res << endl;
    else
      cout << "SYJKGW" << endl;
  }

  return 0;
}