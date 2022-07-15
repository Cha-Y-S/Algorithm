#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl "\n"
#define INF 50001

typedef pair<int, int> pii;

vector<vector<int>> graph;
vector<int> dist;
int N, M, A, B, res_d, res_v, res_c;

void bfs();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

  graph = vector<vector<int>>(N);
  dist = vector<int>(N, INF);
  res_d = res_v = res_c = 0;

  for (int i = 0; i < M; i++) {
    cin >> A >> B;

    graph[A - 1].push_back(B - 1);
    graph[B - 1].push_back(A - 1);
  }

  bfs();

  for (int i = 1; i < N; i++) {
    if (res_d < dist[i]) {
      res_d = dist[i];
      res_v = i + 1;
      res_c = 1;
    } else if (res_d == dist[i])
      res_c++;
  }

  cout << res_v << " " << res_d << " " << res_c << endl;

  return 0;
}

void bfs() {
  queue<pii> q;

  q.push({0, 0});
  dist[0] = 0;

  while (!q.empty()) {
    int cv = q.front().first;
    int cd = q.front().second;

    q.pop();

    for (int nv : graph[cv]) {
      if (dist[nv] > cd + 1) {
        q.push({nv, cd + 1});
        dist[nv] = cd + 1;
      }
    }
  }
}