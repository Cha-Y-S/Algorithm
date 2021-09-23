#include <iostream>
#include <map>
#include <string>

using namespace std;

#define endl "\n"

map<string, bool> M;
int n, m;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;

  int cnt = 0;

  for (int i = 0; i < n; i++) {
    string s;

    cin >> s;

    M[s] = true;
  }

  for (int i = 0; i < m; i++) {
    string s;

    cin >> s;

    if (M[s] == true) cnt++;
  }

  cout << cnt << endl;

  return 0;
}