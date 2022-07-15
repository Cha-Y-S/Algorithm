#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<int, int> pii;

vector<vector<pii>> tree;
vector<bool> visited;

int start;
int diameter;

void dfs(int s, int sum);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int v;

  cin >> v;

  tree = vector<vector<pii>>(v);
  visited = vector<bool>(v, false);

  for (int i = 0; i < v; i++) {
    int parent, child, weight;

    cin >> parent;

    while (true) {
      cin >> child;

      if (child == -1) break;

      cin >> weight;

      tree[parent - 1].push_back({child - 1, weight});
    }
  }

  dfs(start = 0, diameter = 0);

  visited = vector<bool>(v, false);

  dfs(start, diameter = 0);

  cout << diameter << endl;

  return 0;
}

void dfs(int s, int sum) {
  if (visited[s]) return;

  if (sum > diameter) {
    diameter = sum;
    start = s;
  }
  visited[s] = true;

  for (pii p : tree[s]) {
    if (!visited[p.first]) dfs(p.first, sum + p.second);
  }
}