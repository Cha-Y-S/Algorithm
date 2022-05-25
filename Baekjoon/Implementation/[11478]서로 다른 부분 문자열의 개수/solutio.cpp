#include <iostream>
#include <set>
#include <string>

using namespace std;

#define endl "\n"

set<string> sub;
string S, tmp;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> S;

  for (int i = 0; i < S.length(); i++) {
    tmp = "";
    for (int j = i; j < S.length(); j++) {
      tmp += S[j];
      sub.insert(tmp);
    }
  }

  cout << sub.size() << endl;

  return 0;
}