#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl "\n"
#define INF 654'321'987
#define CLIP(X) ((X) > (INF) ? INF : X)

typedef pair<int, int> pii;

vector<vector<pii>> graph;
vector<vector<int>> dist;
int N, E, A, B, C, V1, V2;
int path1, path2, res;

void dijkstra(int dim, int start);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> E;

  graph = vector<vector<pii>>(N);
  dist = vector<vector<int>>(3, vector<int>(N, INF));

  for (int i = 0; i < E; i++) {
    cin >> A >> B >> C;

    graph[A - 1].push_back({C, B - 1});
    graph[B - 1].push_back({C, A - 1});
  }

  cin >> V1 >> V2;

  dijkstra(0, 0);
  dijkstra(1, V1 - 1);
  dijkstra(2, V2 - 1);

  path1 = dist[0][V1 - 1] + dist[1][V2 - 1] + dist[2][N - 1];
  path1 = CLIP(path1);
  path2 = dist[0][V2 - 1] + dist[2][V1 - 1] + dist[1][N - 1];
  path2 = CLIP(path2);

  res = path1 == INF && path2 == INF ? -1 : (path1 < path2 ? path1 : path2);

  cout << res << endl;

  return 0;
}

void dijkstra(int dim, int start) {
  priority_queue<pii, vector<pii>, greater<pii>> pq;

  dist[dim][start] = 0;

  pq.push({dist[dim][start], start});

  while (!pq.empty()) {
    int cw = pq.top().first;
    int cv = pq.top().second;

    pq.pop();

    if (dist[dim][cv] < cw) continue;

    for (pii u : graph[cv]) {
      int nw = u.first;
      int nv = u.second;

      if (dist[dim][nv] > cw + nw) {
        dist[dim][nv] = cw + nw;
        pq.push({dist[dim][nv], nv});
      }
    }
  }
}
