#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl "\n"
typedef pair<int, int> pii;

vector<vector<pii>> par;
vector<int> cnt;
vector<int> parts;
vector<int> res;
int N, M;

void print_info();
void topological_sort();
void print_res();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

  par = vector<vector<pii>>(N);
  cnt = vector<int>(N, 0);
  parts = vector<int>(N, 0);

  for (int i = 0; i < M; i++) {
    int x, y, k;

    cin >> x >> y >> k;

    par[x - 1].push_back({y - 1, k});
    cnt[y - 1]++;
  }

  topological_sort();

  print_res();

  return 0;
}

void topological_sort() {
  queue<int> q;

  q.push(N - 1);
  parts[N - 1] = 1;

  while (!q.empty()) {
    int cur = q.front();

    q.pop();

    if (par[cur].empty())
      res.push_back(cur);

    for (int i = 0; i < par[cur].size(); i++) {
      int next = par[cur][i].first;
      int part = par[cur][i].second;

      parts[next] += parts[cur] * part;

      if (--cnt[next] == 0) q.push(next);
    }
  }

  sort(res.begin(), res.end());
}

void print_res() {
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] + 1 << " " << parts[res[i]] << endl;
  }
}