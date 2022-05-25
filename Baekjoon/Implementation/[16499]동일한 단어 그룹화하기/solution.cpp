#include <algorithm>
#include <iostream>
#include <set>
#include <string>

using namespace std;

#define endl "\n"

set<string> s;
string word;
int N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> word;

    sort(word.begin(), word.end());

    s.insert(word);
  }

  cout << s.size() << endl;

  return 0;
}