#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<int, int> pii;

vector<vector<pii>> tree;
vector<bool> visited;
int diameter;
int vertex;

void dfs(int v, int sum);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;

  cin >> n;

  tree = vector<vector<pii>>(n);
  visited = vector<bool>(n, false);

  for (int i = 0; i < n - 1; i++) {
    int parent, child, weight;

    cin >> parent >> child >> weight;

    tree[parent - 1].push_back({child - 1, weight});
    tree[child - 1].push_back({parent - 1, weight});
  }

  vertex = 0;
  diameter = 0;
  dfs(0, 0);

  visited = vector<bool>(n, false);
  dfs(vertex, 0);

  cout << diameter << endl;

  return 0;
}

void dfs(int v, int sum) {
  if (visited[v]) return;

  visited[v] = true;
  if (sum > diameter) {
    diameter = sum;
    vertex = v;
  }

  for (pii p : tree[v]) {
    if (!visited[p.first]) dfs(p.first, sum + p.second);
  }
}