#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<int, int> pii;

vector<vector<int>> graph;
vector<bool> visited;
int N, M, X, Y, x, y;

int bfs(int sv, int fv);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  graph = vector<vector<int>>(N);
  visited = vector<bool>(N, false);

  cin >> X >> Y;

  cin >> M;

  for (int i = 0; i < M; i++) {
    cin >> x >> y;

    graph[x - 1].push_back(y - 1);
    graph[y - 1].push_back(x - 1);
  }

  cout << bfs(X - 1, Y - 1) << endl;

  return 0;
}

int bfs(int sv, int fv) {
  queue<pii> q;
  int result = -1;

  q.push({sv, 0});
  visited[sv] = true;

  while (!q.empty()) {
    int cv = q.front().first;
    int cc = q.front().second;

    if (cv == fv) {
      result = cc;
      break;
    }

    q.pop();

    for (int nv : graph[cv]) {
      if (visited[nv]) continue;

      q.push({nv, cc + 1});
      visited[nv] = true;
    }
  }

  return result;
}