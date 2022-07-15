#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define endl "\n"

map<int, vector<int>> tree;
vector<int> parent;
vector<int> weight;
vector<int> dp;
int n, m;

void dfs(int s, int w);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;

  parent = vector<int>(n + 1);
  weight = vector<int>(n + 1, 0);
  dp = vector<int>(n, 0);

  for (int i = 1; i <= n; i++)
    cin >> parent[i];

  for (int i = 0; i < m; i++) {
    int v, w;

    cin >> v >> w;

    weight[v] += w;
  }

  for (int i = 2; i <= n; i++)
    tree[parent[i]].push_back(i);

  dfs(1, weight[1]);

  for (int i = 0; i < dp.size(); i++)
    cout << dp[i] << " ";
  cout << endl;

  return 0;
}

void dfs(int s, int w) {
  if (s > n) return;

  int w_cur = w + weight[s];

  dp[s - 1] = w_cur;

  for (auto c : tree[s])
    dfs(c, w_cur);
}