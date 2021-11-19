#include <climits>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"
#define INF INT_MAX

typedef pair<pair<int, int>, int> edge;

vector<edge> edges;
vector<long long> dist;
int N, M;

void bellman_ford();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

  dist = vector<long long>(N, INF);
  edges = vector<edge>(M, {{0, 0}, INF});

  for (int i = 0; i < M; i++) {
    int u, v, weight;

    cin >> u >> v >> weight;

    edges[i] = {{u - 1, v - 1}, weight};
  }

  bellman_ford();

  return 0;
}

void bellman_ford() {
  dist[0] = 0;

  for (int i = 0; i < N - 1; i++) {
    for (int j = 0; j < M; j++) {
      int u = edges[j].first.first;
      int v = edges[j].first.second;
      int w = edges[j].second;

      if (dist[u] == INF) continue;

      if (dist[v] > dist[u] + w) dist[v] = dist[u] + w;
    }
  }

  for (int i = 0; i < M; i++) {
    int u = edges[i].first.first;
    int v = edges[i].first.second;
    int w = edges[i].second;

    if (dist[u] == INF) continue;

    if (dist[v] > dist[u] + w) {
      cout << -1 << endl;
      return;
    }
  }

  for (int i = 1; i < N; i++) {
    if (dist[i] == INF)
      cout << -1 << endl;
    else
      cout << dist[i] << endl;
  }
}