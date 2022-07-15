#include <iostream>
#include <set>
#include <string>

using namespace std;

set<string> s;
string input;
int N;

void check_string(string target);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> input;

    check_string(input);
  }

  cout << (int)s.size() << endl;

  return 0;
}

void check_string(string target) {
  for (string temp : s) {
    if (temp.size() != target.size()) continue;

    for (int i = 0; i < target.size(); i++) {
      if (temp == target) return;
      target += target[0];
      target.erase(0, 1);
    }
  }
  s.insert(target);
}