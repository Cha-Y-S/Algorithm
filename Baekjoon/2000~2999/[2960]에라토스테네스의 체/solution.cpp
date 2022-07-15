#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, k;

  cin >> n >> k;

  vector<bool> removed(n + 1, false);

  for (int i = 2; i < n + 1; i++) {
    if (removed[i]) continue;
    for (int j = i; j < n + 1; j += i) {
      if (removed[j]) continue;
      removed[j] = true;
      if (!(--k)) {
        cout << j << endl;
        break;
      }
    }
    if (!k) break;
  }

  return 0;
}