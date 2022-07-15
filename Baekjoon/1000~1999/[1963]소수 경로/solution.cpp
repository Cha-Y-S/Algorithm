#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#define endl "\n"
#define MAX 10001

string bfs(vector<bool> e, int s, int d);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<bool> eratos(MAX, true);

  eratos[0] = eratos[1] = false;
  for (int i = 2; i * i <= MAX; i++) {
    if (!eratos[i]) continue;
    for (int j = i + i; j < MAX; j += i) {
      eratos[j] = false;
    }
  }

  int t, s, d;

  cin >> t;

  for (; t > 0; t--) {
    cin >> s >> d;

    cout << bfs(eratos, s, d) << endl;
  }

  return 0;
}

string bfs(vector<bool> e, int s, int d) {
  string result = "Impossible";
  vector<bool> visited(MAX, false);
  queue<pair<int, int>> q;

  q.push({s, 0});
  visited[s] = true;

  while (!q.empty()) {
    int cp = q.front().first;
    int cnt = q.front().second;

    q.pop();

    if (cp == d) {
      result = to_string(cnt);
      break;
    }

    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 10; j++) {
        string temp = to_string(cp);
        temp[i] = j + '0';
        int np = stoi(temp);

        if (1000 <= np && np < 10000 && e[np] && !visited[np]) {
          visited[np] = true;
          q.push({np, cnt + 1});
        }
      }
    }
  }
  return result;
}