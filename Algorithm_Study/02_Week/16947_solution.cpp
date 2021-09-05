#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void dfs(int v);

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

  dfs(0);
  cout << endl;

  return 0;
}

void dfs(int v) {
  if (visited[v]) return;
  visited[v] = true;

  cout << v + 1 << " ";
  for (int t : graph[v]) {
    if (!visited[t]) dfs(t);
  }
}