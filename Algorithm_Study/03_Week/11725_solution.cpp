#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<vector<int>> tree;
vector<int> parent;
vector<bool> visited;
int n;

void dfs(int p, int v);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;

  tree = vector<vector<int>>(n + 1);
  parent = vector<int>(n + 1);
  visited = vector<bool>(n + 1, false);

  for (int i = 1; i < n; i++) {
    int v, u;

    cin >> v >> u;

    tree[v].push_back(u);
    tree[u].push_back(v);
  }

  dfs(0, 1);

  for (int i = 2; i <= n; i++)
    cout << parent[i] << endl;

  return 0;
}

void dfs(int p, int v) {
  if (visited[v]) return;

  visited[v] = true;
  parent[v] = p;

  for (int u : tree[v])
    dfs(v, u);
}