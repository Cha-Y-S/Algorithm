#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl "\n"

int bfs(int l, pair<int, int> c, pair<int, int> t);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t, l;

  cin >> t;

  for (; t > 0; t--) {
    pair<int, int> current(-1, -1);
    pair<int, int> target(-1, -1);

    cin >> l;
    cin >> current.first >> current.second;
    cin >> target.first >> target.second;

    cout << bfs(l, current, target) << endl;
  }

  return 0;
}

int bfs(int l, pair<int, int> c, pair<int, int> t) {
  vector<vector<int>> move(l, vector<int>(l, 0));
  vector<pair<int, int>> dir = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
  queue<pair<int, int>> q;

  q.push(c);

  while (!q.empty()) {
    int cx = q.front().first;
    int cy = q.front().second;

    if (cx == t.first && cy == t.second) break;

    q.pop();

    for (int i = 0; i < dir.size(); i++) {
      int nx = cx + dir[i].first;
      int ny = cy + dir[i].second;

      if ((0 <= nx && nx < l) && (0 <= ny && ny < l)) {
        if (!move[nx][ny]) {
          q.push({nx, ny});
          move[nx][ny] = move[cx][cy] + 1;
        }
      }
    }
  }

  return move[t.first][t.second];
}