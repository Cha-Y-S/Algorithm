#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl "\n"
#define INF 987'654'321

typedef pair<int, int> pii;

vector<vector<pii>> graph;
vector<int> dist, route, t_route, path;
int N, M, S, E, W, res;

void dijkstra(int start, int finish);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;
  graph = vector<vector<pii>>(N);
  dist = vector<int>(N, INF);
  route = vector<int>(N, -1);

  for (int i = 0; i < M; i++) {
    cin >> S >> E >> W;

    graph[S - 1].push_back({E - 1, W});
  }

  cin >> S >> E;

  dijkstra(S - 1, E - 1);

  return 0;
}

void dijkstra(int start, int finish) {
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  pq.push({0, start});
  dist[start] = 0;

  while (!pq.empty()) {
    int cost = pq.top().first;
    int cur = pq.top().second;

    pq.pop();

    if (cost > dist[cur]) continue;

    for (int i = 0; i < graph[cur].size(); i++) {
      int next = graph[cur][i].first;
      int n_cost = graph[cur][i].second;

      if (dist[next] > cost + n_cost) {
        route[next] = cur;
        dist[next] = cost + n_cost;
        pq.push({dist[next], next});
      }
    }
  }

  cout << dist[finish] << endl;

  int temp = finish;
  while (temp != -1) {
    t_route.push_back(temp);
    temp = route[temp];
  }
  cout << t_route.size() << endl;

  for (int i = t_route.size() - 1; i >= 0; i--) cout << t_route[i] + 1 << " ";
  cout << endl;
}