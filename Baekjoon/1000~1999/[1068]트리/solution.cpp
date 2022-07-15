#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<vector<int>> tree;
vector<int> parent;
int leaf = 0;

void dfs(int v);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, remove, root;

  cin >> n;

  tree = vector<vector<int>>(n);
  parent = vector<int>(n);

  for (int i = 0; i < n; i++) {
    cin >> parent[i];
    if (parent[i] == -1) root = i;
  }

  cin >> remove;

  parent[remove] = -1;

  for (int i = 0; i < n; i++)
    if (parent[i] != -1) tree[parent[i]].push_back(i);

  if (remove != root) dfs(root);

  cout << leaf << endl;

  return 0;
}

void dfs(int v) {
  if (tree[v].size() == 0) {
    leaf++;
    return;
  }

  for (int u : tree[v])
    dfs(u);
}