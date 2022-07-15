#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define endl "\n"

string s;
vector<string> suffix;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> s;

  while (s.size() > 0) {
    suffix.push_back(s);
    s = s.substr(1);
  }

  sort(suffix.begin(), suffix.end());

  for (int i = 0; i < suffix.size(); i++) {
    cout << suffix[i] << endl;
  }

  return 0;
}