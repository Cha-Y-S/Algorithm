#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl "\n"

vector<int> building;
vector<vector<int>> par;
vector<vector<int>> child;
vector<int> cnt;
vector<int> res;
int T, N, K, X, Y, W;

void topological_sort();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> T;

  for (; T > 0; T--) {
    cin >> N >> K;

    building = vector<int>(N);
    par = vector<vector<int>>(N);
    child = vector<vector<int>>(N);
    cnt = vector<int>(N, 0);
    res = vector<int>(N);

    for (int i = 0; i < N; i++)
      cin >> building[i];

    for (int i = 0; i < K; i++) {
      cin >> X >> Y;

      par[X - 1].push_back(Y - 1);
      child[Y - 1].push_back(X - 1);
      cnt[Y - 1]++;
    }

    cin >> W;

    topological_sort();

    cout << res[W - 1] << endl;

    building.clear();
    par.clear();
    child.clear();
    cnt.clear();
    res.clear();
  }

  return 0;
}

void topological_sort() {
  queue<int> q;

  for (int i = 0; i < cnt.size(); i++) {
    if (cnt[i] == 0) q.push(i);
  }

  while (!q.empty()) {
    int cur = q.front();

    q.pop();

    if (child[cur].size() == 0)
      res[cur] = building[cur];
    else {
      int max_cost = -1;

      for (int i = 0; i < child[cur].size(); i++) {
        if (max_cost < res[child[cur][i]]) max_cost = res[child[cur][i]];
      }

      res[cur] = building[cur] + max_cost;
    }

    for (int i = 0; i < par[cur].size(); i++) {
      if (--cnt[par[cur][i]] == 0)
        q.push(par[cur][i]);
    }
  }
}