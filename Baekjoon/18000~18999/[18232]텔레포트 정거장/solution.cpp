#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<int, int> pii;

vector<vector<int>> teleport;
vector<bool> visited;
int N, M, S, E, X, Y;

int bfs(int start, int finish);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;
  cin >> S >> E;

  teleport = vector<vector<int>>(N + 1);
  visited = vector<bool>(N + 1, false);

  for (int i = 0; i < M; i++) {
    cin >> X >> Y;

    teleport[X].push_back(Y);
    teleport[Y].push_back(X);
  }

  cout << bfs(S, E) << endl;

  return 0;
}

int bfs(int start, int finish) {
  queue<pii> q;
  int result = 0;

  q.push({start, 0});
  visited[start] = true;

  while (!q.empty()) {
    int cv = q.front().first;
    int cc = q.front().second;

    if (cv == finish) {
      result = cc;
      break;
    }

    q.pop();

    vector<int> nvs = {cv + 1, cv - 1};

    for (int nv : teleport[cv])
      nvs.push_back(nv);

    for (int nv : nvs) {
      if (nv > N || nv < 0 || visited[nv]) continue;
      q.push({nv, cc + 1});
      visited[nv] = true;
    }
  }

  return result;
}