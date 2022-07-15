#include <iostream>
#include <map>
#include <string>

using namespace std;

#define endl "\n"

int T, N, res;

int combination(int n, int r);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> T;

  for (; T > 0; T--) {
    cin >> N;

    map<string, int> m;

    for (int i = 0; i < N; i++) {
      string clothes, group;

      cin >> clothes >> group;

      if (m.find(group) == m.end())
        m[group] = 1;
      else
        m[group]++;
    }

    res = 1;
    for (pair<string, int> item : m)
      res *= (item.second + 1);

    cout << res - 1 << endl;
  }

  return 0;
}