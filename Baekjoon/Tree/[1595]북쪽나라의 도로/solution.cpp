#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"
#define MAX_V 10'001

typedef pair<int, int> pii;

vector<vector<pii>> graph;
vector<bool> visited;
int E, V, D;

void dfs(int v, int w);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  graph = vector<vector<pii>>(MAX_V);
  visited = vector<bool>(MAX_V, false);
  V = 1;
  D = 0;

  int u, v, w;
  while (cin >> u >> v >> w) {
    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
    E++;
  }

  dfs(V, 0);

  visited = vector<bool>(MAX_V, false);
  dfs(V, 0);

  cout << D << endl;

  return 0;
}

void dfs(int v, int w) {
  if (visited[v]) return;

  visited[v] = true;

  if (w > D) {
    D = w;
    V = v;
  }

  for (pii p : graph[v]) {
    if (!visited[p.first]) dfs(p.first, w + p.second);
  }
}