#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 1000001
#define endl "\n"

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<bool> eratos(MAX, true);

  eratos[0] = eratos[1] = false;
  for (int i = 2; i <= sqrt(MAX) + 1; i++) {
    if (!eratos[i]) continue;

    for (int j = i + i; j < MAX; j += i)
      if (eratos[j]) eratos[j] = false;
  }

  int t, n;

  cin >> t;

  for (; t > 0; t--) {
    cin >> n;

    int cnt = 0;

    for (int i = 2; i <= n / 2; i++)
      if (eratos[i] && eratos[n - i]) cnt++;

    cout << cnt << endl;
  }

  return 0;
}