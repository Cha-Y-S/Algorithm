#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

#define endl "\n"

vector<string> words;
vector<bool> visited;
set<char> s;
map<char, int> m;
int N, answer, kinds;

void set_number(int cnt);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  words = vector<string>(N);
  visited = vector<bool>(10, false);
  answer = 0;

  for (int i = 0; i < N; i++) {
    cin >> words[i];

    for (int j = 0; j < words[i].size(); j++)
      s.insert(words[i][j]);
  }

  kinds = s.size();

  set_number(0);

  cout << answer << endl;

  return 0;
}

void set_number(int cnt) {
  if (cnt == s.size()) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
      int temp = 0;
      for (int j = 0; j < words[i].size(); j++) {
        temp *= 10;
        temp += m[words[i][j]];
      }

      sum += temp;
    }

    answer = answer < sum ? sum : answer;

    return;
  }

  set<char>::iterator it = s.begin();
  for (int i = 0; i < cnt; i++)
    it++;
  char current = *it;

  for (int i = 9; i > 9 - kinds; i--) {
    if (visited[i]) continue;
    visited[i] = true;
    m[current] = i;
    set_number(cnt + 1);
    visited[i] = false;
  }
}