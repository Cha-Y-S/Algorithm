#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl "\n"

void bfs(vector<vector<int>> graph, vector<int> &visited, int s);
bool isBipartite(vector<vector<int>> g, vector<int> v);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t, v, e, v1, v2;

  cin >> t;

  for (; t > 0; t--) {
    cin >> v >> e;

    vector<vector<int>> graph(v);
    vector<int> visited(v, 0);

    for (int i = 0; i < e; i++) {
      cin >> v1 >> v2;

      graph[v1 - 1].push_back(v2 - 1);
      graph[v2 - 1].push_back(v1 - 1);
    }

    for (int i = 0; i < v; i++) {
      if (visited[i] == 0) bfs(graph, visited, i);
    }

    if (isBipartite(graph, visited))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }

  return 0;
}

void bfs(vector<vector<int>> graph, vector<int> &visited, int s) {
  queue<pair<int, int>> q;

  q.push({s, 1});
  visited[0] = 1;

  while (!q.empty()) {
    int cv = q.front().first;
    int cc = q.front().second;

    q.pop();

    for (int i = 0; i < graph[cv].size(); i++) {
      int nv = graph[cv][i];
      int nc = cc == 1 ? 2 : 1;
      if (visited[nv] == 0) {
        visited[nv] = nc;
        q.push({nv, nc});
      }
    }
  }
}

bool isBipartite(vector<vector<int>> g, vector<int> v) {
  for (int i = 0; i < g.size(); i++) {
    for (int j = 0; j < g[i].size(); j++) {
      if (v[i] == v[g[i][j]]) return false;
    }
  }
  return true;
}