#include <cmath>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define endl "\n"
#define MAX 100001

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<bool> eratos(MAX, true);
  int t, n;

  eratos[0] = eratos[1] = false;

  for (int i = 2; i <= sqrt(MAX) + 1; i++) {
    if (!eratos[i]) continue;

    for (int j = i + i; j < MAX; j += i) {
      if (eratos[j])
        eratos[j] = false;
    }
  }

  cin >> t;

  for (; t > 0; t--) {
    cin >> n;

    map<int, int> m;

    for (int i = 2; i <= n; i++) {
      if (eratos[i] && n % i == 0) {
        m[i]++;
        n /= i;
        i--;
      }
    }

    for (auto it : m)
      cout << it.first << " " << it.second << endl;
  }

  return 0;
}