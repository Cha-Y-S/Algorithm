#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree;
vector<int> parent;
vector<bool> visited;
vector<int> level;
int n, m;

void findParent(int v, int u);
void dfs(int pv, int v, int l);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;

  tree = vector<vector<int>>(n);
  parent = vector<int>(n, -1);
  visited = vector<bool>(n, false);
  level = vector<int>(n, 0);

  for (int i = 0; i < n - 1; i++) {
    int v, u;

    cin >> v >> u;

    tree[v - 1].push_back(u - 1);
    tree[u - 1].push_back(v - 1);
  }

  dfs(-1, 0, 0);

  cin >> m;

  for (int i = 0; i < m; i++) {
    int v, u;

    cin >> v >> u;

    v -= 1;
    u -= 1;

    if (level[v] == level[u]) {
      findParent(v, u);
    } else if (level[v] > level[u]) {
      while (level[v] != level[u])
        v = parent[v];

      findParent(v, u);
    } else {
      while (level[v] != level[u])
        u = parent[u];
      findParent(v, u);
    }
  }

  return 0;
}

void dfs(int pv, int v, int l) {
  if (visited[v]) return;

  visited[v] = true;
  parent[v] = pv;
  level[v] = l;

  for (int u : tree[v]) {
    if (!visited[u]) dfs(v, u, l + 1);
  }
}

void findParent(int v, int u) {
  if (v == u) {
    cout << v + 1 << endl;
    return;
  }

  while (parent[v] != parent[u]) {
    v = parent[v];
    u = parent[u];
  }
  cout << parent[v] + 1 << endl;
}