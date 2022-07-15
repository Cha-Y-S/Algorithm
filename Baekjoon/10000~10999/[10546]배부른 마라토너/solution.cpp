#include <iostream>
#include <map>
#include <string>

using namespace std;

#define endl "\n"

map<string, int> player;
string p;
int N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> p;

    player[p]++;
  }

  for (int i = 0; i < N - 1; i++) {
    cin >> p;

    player[p]--;
  }

  for (pair<string, int> t : player) {
    if (t.second != 0) {
      cout << t.first << endl;
      break;
    }
  }

  return 0;
}