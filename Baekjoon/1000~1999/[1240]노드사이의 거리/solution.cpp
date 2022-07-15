#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<int, int> pii;

vector<vector<pii>> tree;
vector<bool> visited;
int n, m;

void dfs(int v, int t, int d);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;

  tree = vector<vector<pii>>(n);

  for (int i = 1; i < n; i++) {
    int u, v, w;

    cin >> u >> v >> w;

    u -= 1;
    v -= 1;

    tree[u].push_back({v, w});
    tree[v].push_back({u, w});
  }

  for (int i = 0; i < m; i++) {
    int u, v;

    cin >> u >> v;

    u -= 1;
    v -= 1;

    visited = vector<bool>(n, false);

    dfs(u, v, 0);
  }

  return 0;
}

void dfs(int v, int t, int d) {
  if (visited[v]) return;

  if (v == t) {
    cout << d << endl;
    return;
  }

  visited[v] = true;

  for (pii next : tree[v]) {
    int u = next.first;
    int w = next.second;
    dfs(u, t, d + w);
  }
}