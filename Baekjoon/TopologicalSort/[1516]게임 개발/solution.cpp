#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> par;
vector<int> building;
vector<int> cnt;
vector<int> res;
int N;

void topological_sort();
void print_res();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  building = vector<int>(N);
  par = vector<vector<int>>(N);
  cnt = vector<int>(N, 0);
  res = vector<int>(N);

  for (int i = 0; i < N; i++) {
    int w, c;

    cin >> w >> c;

    building[i] = w;

    while (c != -1) {
      par[c - 1].push_back(i);
      cnt[i]++;

      cin >> c;
    }
  }

  topological_sort();

  print_res();

  return 0;
}

void topological_sort() {
  queue<int> q;

  for (int i = 0; i < N; i++) {
    if (cnt[i] == 0) {
      q.push(i);
      res[i] = building[i];
    }
  }

  while (!q.empty()) {
    int cur = q.front();

    q.pop();

    for (int i = 0; i < par[cur].size(); i++) {
      res[par[cur][i]] = max(res[par[cur][i]], res[cur] + building[par[cur][i]]);
      if (--cnt[par[cur][i]] == 0) q.push(par[cur][i]);
    }
  }
}

void print_res() {
  for (int i = 0; i < N; i++)
    cout << res[i] << endl;
}