#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"
#define MAX 1300001

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<bool> eratos(MAX, true);
  int t, k;

  eratos[0] = eratos[1] = false;
  for (int i = 2; i * i < MAX; i++) {
    if (!eratos[i]) continue;
    for (int j = i + i; j < MAX; j += i)
      eratos[j] = false;
  }

  cin >> t;

  for (; t > 0; t--) {
    int cnt = 1;

    cin >> k;

    if (eratos[k]) {
      cout << 0 << endl;
      continue;
    }

    for (int i = k - 1; i > 0; i--) {
      if (eratos[i]) break;
      cnt++;
    }

    for (int i = k; i < MAX; i++) {
      if (eratos[i]) break;
      cnt++;
    }
    cout << cnt << endl;
  }

  return 0;
}