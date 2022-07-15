#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<int, int> pii;

vector<vector<int>> par;
vector<int> child;
vector<int> res;
int N, M, pre, post;

void topological_sort();
void print_res();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

  par = vector<vector<int>>(N + 1);
  child = vector<int>(N + 1, 0);
  res = vector<int>(N + 1, 0);

  for (int i = 0; i < M; i++) {
    cin >> pre >> post;

    par[pre].push_back(post);
    child[post]++;
  }

  topological_sort();

  print_res();

  return 0;
}

void topological_sort() {
  queue<pii> q;

  for (int i = 1; i <= N; i++) {
    if (child[i] == 0) q.push({i, 1});
  }

  while (!q.empty()) {
    int cv = q.front().first;
    int cc = q.front().second;

    q.pop();

    res[cv] = cc;

    for (int i = 0; i < par[cv].size(); i++) {
      if (--child[par[cv][i]] == 0) q.push({par[cv][i], cc + 1});
    }
  }
}

void print_res() {
  for (int i = 1; i <= N; i++)
    cout << res[i] << " ";
  cout << endl;
}