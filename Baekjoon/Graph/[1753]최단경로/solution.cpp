#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<vector<pair<int, int>>> graph;
  vector<int> distance;
  const int INF = INT_MAX;
  int nv, ne;
  int sv;

  cin >> nv >> ne >> sv;

  // Initialize graph and distance
  for (int i = 0; i < nv; i++) {
    vector<pair<int, int>> temp;
    graph.push_back(temp);
    distance.push_back(INF);
  }

  // Input
  for (int i = 0; i < ne; i++) {
    int u, v, w;

    cin >> u >> v >> w;

    graph[u - 1].push_back(make_pair(w, v - 1));
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

  // Distance of start vertex is 0
  distance[sv - 1] = 0;

  // Push start vertex into the priority queue
  pq.push({distance[sv - 1], sv - 1});

  while (!pq.empty()) {
    // Get vertex that have lowest weight
    int dist = pq.top().first;
    int v = pq.top().second;

    pq.pop();

    // If distance of vertex is already lower than cost, do nothing
    if (distance[v] != dist) continue;

    for (int i = 0; i < graph[v].size(); i++) {
      int cost = graph[v][i].first;
      int w = graph[v][i].second;

      // Update lowest distance of w that is from v
      if (distance[w] > dist + cost) {
        distance[w] = dist + cost;
        pq.push({distance[w], w});
      }
    }
  }

  for (int i = 0; i < nv; i++) {
    if (distance[i] == INF)
      cout << "INF\n";
    else
      cout << distance[i] << "\n";
  }

  return 0;
}