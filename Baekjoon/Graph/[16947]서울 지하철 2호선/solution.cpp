#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl "\n"

vector<vector<int>> station;
vector<bool> check;
vector<bool> visited;
vector<int> res;
bool cycle;
int N;

void dfs(int cur, int start, int cnt);
int bfs(int v);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  station = vector<vector<int>>(N);
  visited = vector<bool>(N, false);
  check = vector<bool>(N, false);

  for (int i = 0; i < N; i++) {
    int v1, v2;

    cin >> v1 >> v2;

    station[v1 - 1].push_back(v2 - 1);
    station[v2 - 1].push_back(v1 - 1);
  }

  for (int i = 0; i < N; i++) {
    visited = vector<bool>(N, false);
    cycle = false;

    int start = i;

    dfs(i, start, 0);

    if (cycle) check[i] = true;

    visited.clear();
  }

  for (int i = 0; i < N; i++) {
    if (check[i]) {
      res.push_back(0);
      continue;
    }
    res.push_back(bfs(i));

    visited.clear();
  }

  for (int i = 0; i < res.size(); i++)
    cout << res[i] << " ";
  cout << endl;

  return 0;
}

void dfs(int cur, int start, int cnt) {
  if (cur == start && cnt >= 2) {
    cycle = true;
    return;
  }

  visited[cur] = true;

  for (int i = 0; i < station[cur].size(); i++) {
    int next = station[cur][i];

    if (!visited[next])
      dfs(next, start, cnt + 1);
    else {
      if (next == start && cnt >= 2) dfs(next, start, cnt);
    }

    if (cycle == true) return;
  }
}

int bfs(int v) {
  visited = vector<bool>(N, false);
  queue<pair<int, int>> q;

  q.push({v, 0});
  visited[v] = true;

  while (!q.empty()) {
    int cur = q.front().first;
    int cnt = q.front().second;

    q.pop();

    if (check[cur]) {
      return cnt;
    }

    for (int i = 0; i < station[cur].size(); i++) {
      int next = station[cur][i];

      if (!visited[next]) {
        visited[next] = true;
        q.push({next, cnt + 1});
      }
    }
  }
}