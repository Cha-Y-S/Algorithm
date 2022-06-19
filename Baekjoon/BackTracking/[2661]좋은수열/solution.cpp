#include <iostream>
#include <string>

using namespace std;

#define endl "\n"

string S;
int N;
bool flag;

void generate_sequence(string s, int depth);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;
  flag = false;

  generate_sequence(S, 0);

  return 0;
}

void generate_sequence(string s, int depth) {
  if (flag) return;

  int len = s.size();

  for (int i = 1; i <= (len / 2); i++) {
    if (s.substr(len - i, i) == s.substr(len - (2 * i), i)) {
      s = "";
      return;
    }
  }

  if (depth > N) return;

  if (depth == N) {
    flag = true;
    cout << s << endl;
    return;
  } else {
    for (int i = 0; i < N; i++) {
      generate_sequence(s + "1", depth + 1);
      generate_sequence(s + "2", depth + 1);
      generate_sequence(s + "3", depth + 1);
    }
  }
}