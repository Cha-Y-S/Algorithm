#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define INF INT_MAX
#define endl "\n"

typedef pair<int, int> pii;

vector<vector<pii>> graph;
vector<int> dist;
int N, M, U, V, W;

void dijkstra(int sv);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

  graph = vector<vector<pii>>(N);
  dist = vector<int>(N, INF);

  for (int i = 0; i < M; i++) {
    cin >> U >> V >> W;

    graph[U - 1].push_back({W, V - 1});
  }

  cin >> U >> V;

  dijkstra(U - 1);

  cout << dist[V - 1] << endl;

  return 0;
}

void dijkstra(int sv) {
  priority_queue<pii, vector<pii>, greater<pii>> pq;

  dist[sv] = 0;

  pq.push({dist[sv], sv});

  while (!pq.empty()) {
    int w = pq.top().first;
    int v = pq.top().second;

    pq.pop();

    if (dist[v] != w) continue;

    for (int i = 0; i < graph[v].size(); i++) {
      int cost = graph[v][i].first;
      int u = graph[v][i].second;

      if (dist[u] > w + cost) {
        dist[u] = w + cost;
        pq.push({dist[u], u});
      }
    }
  }
}