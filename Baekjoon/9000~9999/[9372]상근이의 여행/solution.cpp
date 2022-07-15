#include <iostream>

using namespace std;

#define endl "\n"

int t, n, m;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> t;

  for (; t > 0; t--) {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
      int u, v;

      cin >> u >> v;
    }

    cout << n - 1 << endl;
  }

  return 0;
}