#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

#define endl "\n"

string s, res;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> s;

  res = string(s.size(), 'z');

  for (int i = 0; i < s.size() - 2; i++) {
    for (int j = i + 1; j < s.size() - 1; j++) {
      string tmp = s;

      reverse(tmp.begin(), tmp.begin() + i + 1);
      reverse(tmp.begin() + i + 1, tmp.begin() + j + 1);
      reverse(tmp.begin() + j + 1, tmp.end());

      res = min(res, tmp);
    }
  }

  cout << res << endl;

  return 0;
}