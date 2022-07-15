#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl "\n"

vector<vector<int>> par;
vector<int> child;
vector<int> res;
int N, M;

void topological_sort();
void print_res();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

  par = vector<vector<int>>(N + 1);
  child = vector<int>(N + 1, 0);

  for (int i = 0; i < M; i++) {
    int a, b;

    cin >> a >> b;

    par[a].push_back(b);
    child[b]++;
  }

  topological_sort();

  print_res();

  return 0;
}

void print_res() {
  for (int i = 0; i < N; i++)
    cout << res[i] << " ";
  cout << endl;
}

void topological_sort() {
  queue<int> q;

  for (int i = 1; i <= N; i++) {
    if (child[i] == 0) q.push(i);
  }

  while (!q.empty()) {
    int cur = q.front();

    q.pop();

    res.push_back(cur);

    for (int i = 0; i < par[cur].size(); i++) {
      if (--child[par[cur][i]] == 0) q.push(par[cur][i]);
    }
  }
}