#include <climits>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"
#define INF INT_MAX

typedef pair<pair<int, int>, int> edge;

vector<edge> edges;
vector<long long> dist;
vector<int> city;
vector<bool> visited;
int N, S, E, M;

bool bellman_ford();
bool dfs(int cur);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> S >> E >> M;

  edges = vector<edge>(M);
  dist = vector<long long>(N, INF);
  city = vector<int>(N);
  visited = vector<bool>(N, false);

  for (int i = 0; i < M; i++) {
    int u, v, w;

    cin >> u >> v >> w;

    edges[i] = {{u, v}, w};
  }

  for (int i = 0; i < N; i++) {
    cin >> city[i];

    city[i] *= -1;
  }

  if (!bellman_ford()) {
    // If graph has negative cycle
    cout << "Gee" << endl;
  } else {
    cout << (dist[E] == INF ? "gg" : to_string(dist[E] * -1)) << endl;
  }

  return 0;
}

bool bellman_ford() {
  dist[S] = city[S];

  for (int i = 0; i < N - 1; i++) {
    for (int j = 0; j < M; j++) {
      int u = edges[j].first.first;
      int v = edges[j].first.second;
      int w = edges[j].second;

      if (dist[u] == INF) continue;

      if (dist[v] > dist[u] + w + city[v]) {
        dist[v] = dist[u] + w + city[v];
      }
    }
  }

  for (int i = 0; i < M; i++) {
    int u = edges[i].first.first;
    int v = edges[i].first.second;
    int w = edges[i].second;

    if (dist[u] == INF) continue;

    if (dist[v] > dist[u] + w + city[v]) {
      if (dfs(u)) {
        return false;
      }
    }
  }

  return true;
}

bool dfs(int cur) {
  bool result = false;

  if (cur == E) return true;
  visited[cur] = true;

  for (int i = 0; i < M; i++) {
    int u = edges[i].first.first;
    int v = edges[i].first.second;

    if (u == cur && !visited[v])
      result |= dfs(v);
  }

  return result;
}