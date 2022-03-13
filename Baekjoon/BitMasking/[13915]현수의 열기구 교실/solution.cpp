#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

#define endl "\n"

string input;
int N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  while (cin >> N) {
    set<int> s;
    for (int i = 0; i < N; i++) {
      cin >> input;
      int tmp = 0;
      for (int j = 0; j < input.size(); j++) {
        tmp |= 1 << (input[j] - '0' - 1);
      }
      s.insert(tmp);
    }

    cout << s.size() << endl;
  }

  return 0;
}