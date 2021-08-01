#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int solution(int N, vector<vector<int>> road, int K) {
  int answer = 0;
  vector<vector<pair<int, int>>> graph;
  vector<int> distance;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

  // Initialize graph and distance
  for (int i = 0; i < N; i++) {
    vector<pair<int, int>> temp;
    graph.push_back(temp);
    distance.push_back(INT_MAX);
  }

  for (int i = 0; i < road.size(); i++) {
    int u, v, w;

    u = road[i][0] - 1;
    v = road[i][1] - 1;
    w = road[i][2];

    // Undirected graph
    graph[u].push_back(make_pair(w, v));
    graph[v].push_back(make_pair(w, u));
  }

  distance[0] = 0;

  pq.push({distance[0], 0});

  while (!pq.empty()) {
    int dist = pq.top().first;
    int u = pq.top().second;

    pq.pop();

    if (distance[u] != dist) continue;

    for (int i = 0; i < graph[u].size(); i++) {
      int cost = graph[u][i].first;
      int v = graph[u][i].second;

      if (distance[v] > dist + cost) {
        distance[v] = dist + cost;
        pq.push(make_pair(distance[v], v));
      }
    }
  }

  for (int i = 0; i < distance.size(); i++)
    answer = distance[i] <= K ? answer + 1 : answer;

  return answer;
}