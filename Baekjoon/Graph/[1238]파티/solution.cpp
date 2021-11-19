#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl "\n"
#define INF INT_MAX

typedef pair<int, int> pii;

vector<vector<pii>> graph;
vector<vector<int>> dist;
vector<int> res;
int N, M, X;

void dijkstra(int start);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M >> X;

  graph = vector<vector<pii>>(N);
  dist = vector<vector<int>>(N, vector<int>(N, INF));
  res = vector<int>(N, 0);

  for (int i = 0; i < M; i++) {
    int u, v, w;

    cin >> u >> v >> w;

    graph[u - 1].push_back({w, v - 1});
  }

  for (int i = 0; i < N; i++)
    dijkstra(i);

  for (int i = 0; i < N; i++)
    res[i] = dist[i][X - 1] + dist[X - 1][i];

  cout << *max_element(res.begin(), res.end()) << endl;

  return 0;
}

void dijkstra(int start) {
  priority_queue<pii, vector<pii>, greater<pii>> pq;

  dist[start][start] = 0;

  pq.push({dist[start][start], start});

  while (!pq.empty()) {
    int w = pq.top().first;
    int v = pq.top().second;

    pq.pop();

    if (dist[start][v] != w) continue;

    for (int i = 0; i < graph[v].size(); i++) {
      int cost = graph[v][i].first;
      int u = graph[v][i].second;

      if (dist[start][u] > w + cost) {
        dist[start][u] = w + cost;
        pq.push({dist[start][u], u});
      }
    }
  }
}