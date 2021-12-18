#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#define endl "\n"

int T;
int A, B;

string bfs(int a, int b);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> T;

  for (; T > 0; T--) {
    cin >> A >> B;

    cout << bfs(A, B) << endl;
  }

  return 0;
}

string bfs(int a, int b) {
  vector<char> oper = {'D', 'S', 'L', 'R'};
  vector<bool> visited(10000, false);
  queue<pair<int, string>> q;

  q.push({a, ""});
  visited[a] = true;

  while (!q.empty()) {
    int cur_state = q.front().first;
    string cur_oper = q.front().second;

    q.pop();

    if (cur_state == b)
      return cur_oper;

    for (int i = 0; i < oper.size(); i++) {
      int next_state;

      switch (i) {
        case 0:
          next_state = (cur_state * 2) % 10000;
          break;
        case 1:
          next_state = cur_state == 0 ? 9999 : cur_state - 1;
          break;
        case 2:
          next_state = (cur_state % 1000) * 10 + cur_state / 1000;
          break;
        case 3:
          next_state = (cur_state % 10) * 1000 + cur_state / 10;
          break;
      }

      if (!visited[next_state]) {
        q.push({next_state, cur_oper + oper[i]});
        visited[next_state] = true;
      }
    }
  }
}