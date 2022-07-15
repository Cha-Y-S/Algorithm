#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<vector<int>> tree;
vector<int> level;
vector<int> parent;
int t, n, root;

void setLevel(int start, int l);
int findParent(int u, int v);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> t;

  for (; t > 0; t--) {
    cin >> n;

    parent = vector<int>(n, -1);
    tree = vector<vector<int>>(n);
    level = vector<int>(n);

    int root, u, v;

    for (int i = 1; i < n; i++) {
      cin >> u >> v;

      parent[--v] = --u;

      tree[u].push_back(v);
    }

    root = find(parent.begin(), parent.end(), -1) - parent.begin();

    cin >> u >> v;

    setLevel(root, 0);

    if (level[--u] > level[--v]) {
      while (level[u] > level[v])
        u = parent[u];
    } else if (level[u] < level[v]) {
      while (level[u] < level[v])
        v = parent[v];
    }

    cout << findParent(u, v) + 1 << endl;
  }

  return 0;
}

void setLevel(int start, int l) {
  level[start] = l;

  if (tree[start].size() == 0) return;

  for (int v : tree[start])
    setLevel(v, l + 1);
}

int findParent(int u, int v) {
  while (u != v) {
    u = parent[u];
    v = parent[v];
  }
  return u;
}