#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

#define endl "\n"

map<string, int> m;
string s, s_res;
int N, n_res;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;
  n_res = 0;

  for (int i = 0; i < N; i++) {
    cin >> s;

    m[s]++;
  }

  for (pair<string, int> p : m) {
    if (n_res < p.second) {
      s_res = p.first;
      n_res = p.second;
    }
  }

  cout << s_res << endl;

  return 0;
}