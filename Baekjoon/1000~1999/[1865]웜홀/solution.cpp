#include <iostream>
#include <vector>

using namespace std;

#define INF 987'654'312
#define endl "\n"

typedef pair<int, int> pii;
typedef pair<pair<int, int>, int> edge;

vector<edge> edges;
vector<int> dist;
int TC, N, M, W, S, E, T;

bool bellman_ford();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> TC;

  for (; TC > 0; TC--) {
    cin >> N >> M >> W;

    dist = vector<int>(N, INF);

    for (int i = 0; i < M; i++) {
      cin >> S >> E >> T;

      edges.push_back({{S - 1, E - 1}, T});
      edges.push_back({{E - 1, S - 1}, T});
    }

    for (int i = 0; i < W; i++) {
      cin >> S >> E >> T;

      edges.push_back({{S - 1, E - 1}, -T});
    }

    cout << (bellman_ford() ? "YES" : "NO") << endl;

    edges.clear();
  }

  return 0;
}

bool bellman_ford() {
  bool result = false;
  dist[0] = 0;

  for (int i = 0; i < N - 1; i++) {
    for (int j = 0; j < edges.size(); j++) {
      int u = edges[j].first.first;
      int v = edges[j].first.second;
      int w = edges[j].second;

      if (dist[v] > dist[u] + w) dist[v] = dist[u] + w;
    }
  }

  for (int i = 0; i < edges.size(); i++) {
    int u = edges[i].first.first;
    int v = edges[i].first.second;
    int w = edges[i].second;

    if (dist[v] > dist[u] + w) {
      return result = true;
    }
  }

  return result;
}