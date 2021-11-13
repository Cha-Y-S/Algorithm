#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
bool cycle;

void dfs(int p, int v, int cnt);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;

  cin >> n;

  graph = vector<vector<int>>(n);
  visited = vector<bool>(n, false);

  for (int i = 0; i < n; i++) {
    int v1, v2;

    cin >> v1 >> v2;

    graph[v1 - 1].push_back(v2 - 1);
    graph[v2 - 1].push_back(v1 - 1);
  }

  for (int i = 0; i < graph.size(); i++) {
    sort(graph[i].begin(), graph[i].end());
  }

  for (int i = 0; i < graph.size(); i++) {
    cout << i + 1 << ": ";
    for (int j = 0; j < graph[i].size(); j++) {
      cout << graph[i][j] + 1 << " ";
    }
    cout << endl;
  }

  dfs(0, 0, 0);
  cout << endl;

  for (int i = 0; i < visited.size(); i++) {
    cout << visited[i] << " ";
  }

  return 0;
}

void dfs(int p, int c, int cnt) {
  visited[c] = true;

  cout << c + 1 << " ";

  for (int v : graph[c]) {
    if (!visited[v])
      dfs(c, v, cnt + 1);
    else if (p != v && cnt >= 3) {
      cycle = true;
      return;
    }
  }

  if (!cycle) {
    visited[c] = false;
  }
}