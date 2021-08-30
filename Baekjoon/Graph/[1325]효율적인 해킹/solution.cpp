#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

void dfs(vector<vector<int>> &adj, vector<bool> &visited, int &cnt, int v);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;

  cin >> n >> m;

  vector<int> hacking;
  vector<vector<int>> adj(n);

  for (int i = 0; i < m; i++) {
    int a, b;

    cin >> a >> b;

    adj[b - 1].push_back(a - 1);
  }

  for (int i = 0; i < n; i++) {
    vector<bool> visited(adj.size(), false);
    int cnt = 0;
    dfs(adj, visited, cnt, i);
    hacking.push_back(cnt);
  }

  int maximum = *max_element(hacking.begin(), hacking.end());

  for (int i = 0; i < n; i++)
    if (maximum == hacking[i]) cout << i + 1 << " ";

  cout << endl;

  return 0;
}

void dfs(vector<vector<int>> &adj, vector<bool> &visited, int &cnt, int v) {
  visited[v] = true;
  cnt++;

  for (int i = 0; i < adj[v].size(); i++) {
    if (!visited[adj[v][i]]) {
      dfs(adj, visited, cnt, adj[v][i]);
    }
  }
}