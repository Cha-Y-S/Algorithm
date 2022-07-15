#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<vector<int>> tree;
vector<bool> visited;
int n, m, u, v, num_tree, c_cnt;

bool dfs(int p, int v);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  while (true) {
    cin >> n >> m;

    if (n == m && m == 0) break;

    tree = vector<vector<int>>(n);
    visited = vector<bool>(n, false);
    num_tree = 0;

    for (int i = 0; i < m; i++) {
      cin >> u >> v;

      u -= 1;
      v -= 1;

      tree[u].push_back(v);
      tree[v].push_back(u);
    }

    for (int i = 0; i < n; i++) {
      if (!visited[i] && dfs(-1, i))
        num_tree++;
    }

    cout << "Case " << ++c_cnt << ": ";

    if (num_tree == 0)
      cout << "No trees." << endl;
    else if (num_tree == 1)
      cout << "There is one tree." << endl;
    else
      cout << "A forest of " << num_tree << " trees." << endl;
  }

  return 0;
}

bool dfs(int p, int v) {
  visited[v] = true;

  for (int u : tree[v]) {
    if (p == u) continue;
    if (visited[u]) return false;
    if (dfs(v, u) == false) return false;
  }

  return true;
}