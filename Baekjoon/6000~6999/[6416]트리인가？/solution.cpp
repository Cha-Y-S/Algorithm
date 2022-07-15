#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

#define endl "\n"

map<int, vector<int>> tree;
map<int, vector<int>> parent;
int root = 0;
int edge = 0;
int k = 1;

bool bfs();
bool isUniqueRoot();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  while (true) {
    int a, b;

    cin >> a >> b;

    if (a == -1 && b == -1) break;
    if (a == 0 && b == 0) {
      if (tree.size() == 0 || (isUniqueRoot() && bfs())) {
        cout << "Case " << k << " is a tree." << endl;
      } else {
        cout << "Case " << k << " is not a tree." << endl;
      }
      k++;
      root = edge = 0;
      tree.clear();
      parent.clear();
    } else {
      tree[a].push_back(b);
      parent[b].push_back(a);
      edge++;
    }
  }

  return 0;
}

bool isUniqueRoot() {
  int cnt = 0;
  for (auto it : tree) {
    if (parent[it.first].size() == 0) {
      root = it.first;
      cnt++;
    }
    if (cnt > 2) break;
  }

  return cnt == 1;
}

bool bfs() {
  bool result = true;
  int e_cnt = 0;

  set<int> visited;
  queue<int> q;

  q.push(root);
  visited.insert(root);

  while (!q.empty()) {
    int v = q.front();

    q.pop();

    for (auto nv : tree[v]) {
      if (visited.find(nv) == visited.end()) {
        visited.insert(nv);
        e_cnt++;
        q.push(nv);
      } else {
        result = false;
        break;
      }
    }
    if (!result) break;
  }

  if (e_cnt != edge) result = false;

  return result;
}