#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<pair<pair<int, int>, int>> xyr;
vector<vector<int>> g;
vector<bool> visited;

void dfs(int s);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t, n, x, y, r;

  cin >> t;

  for (; t > 0; t--) {
    cin >> n;
    xyr = vector<pair<pair<int, int>, int>>(n, {{-1, -1}, -1});
    g = vector<vector<int>>(n);
    visited = vector<bool>(n, false);
    int group = 0;

    for (int i = 0; i < n; i++) {
      cin >> x >> y >> r;
      xyr[i] = {{x, y}, r};
    }

    for (int i = 0; i < n; i++) {
      int sx = xyr[i].first.first;
      int sy = xyr[i].first.second;
      int sr = xyr[i].second;
      for (int j = i + 1; j < n; j++) {
        int tx = xyr[j].first.first;
        int ty = xyr[j].first.second;
        int tr = xyr[j].second;

        int d = (tx - sx) * (tx - sx) + (ty - sy) * (ty - sy);
        int sum_r = (tr + sr) * (tr + sr);

        if (d <= sum_r) {
          g[i].push_back(j);
          g[j].push_back(i);
        }
      }
    }

    for (int i = 0; i < visited.size(); i++) {
      if (!visited[i]) {
        dfs(i);
        group++;
      }
    }

    cout << group << endl;
  }
  return 0;
}

void dfs(int s) {
  if (visited[s]) return;

  visited[s] = true;

  for (int v : g[s]) {
    if (!visited[v]) dfs(v);
  }
}