#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define endl "\n"

vector<char> res;
string s, boom;
int idx;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> s >> boom;

  res = vector<char>(s.size(), 0);
  idx = 0;

  for (int i = 0; i < s.size(); i++) {
    res[idx++] = s[i];

    if (res[idx - 1] == boom[boom.size() - 1]) {
      if (idx - boom.size() < 0)
        continue;

      bool flag = true;
      for (int j = 0; j < boom.size(); j++) {
        if (res[idx - j - 1] != boom[boom.size() - j - 1]) {
          flag = false;
          break;
        }
      }

      if (flag) idx -= boom.size();
    }
  }

  if (idx == 0)
    cout << "FRULA" << endl;
  else {
    for (int i = 0; i < idx; i++)
      cout << res[i];
    cout << endl;
  }

  return 0;
}
