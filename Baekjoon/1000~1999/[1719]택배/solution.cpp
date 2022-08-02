#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<int, int> pii;

vector<vector<pii>> graph;
vector<vector<int>> res;
vector<int> dist;
int N, M;

void dijkstra(int start);
void update_vertex_number(int standard);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

  res = vector<vector<int>>(N, vector<int>(N));
  graph = vector<vector<pii>>(N);

  for (int i = 0; i < M; i++) {
    int u, v, w;

    cin >> u >> v >> w;

    graph[u - 1].push_back({v - 1, w});
    graph[v - 1].push_back({u - 1, w});
  }

  for (int i = 0; i < N; i++) {
    // 1. execute dijkstra's algorithm about all the vertexes
    dijkstra(i);
    // 3. update the vertex number until the next vertex number will be "-"
    update_vertex_number(i);
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << (res[i][j] < 0 ? "-" : to_string(res[i][j] + 1)) << " ";
    }
    cout << endl;
  }

  return 0;
}

void dijkstra(int start) {
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  dist = vector<int>(N, 987'654'321);

  pq.push({0, start});
  res[start][start] = -1;
  dist[start] = 0;

  while (!pq.empty()) {
    int cv = pq.top().second;
    int cw = pq.top().first;

    pq.pop();

    if (dist[cv] < cw) continue;

    for (int i = 0; i < graph[cv].size(); i++) {
      int nv = graph[cv][i].first;
      int nw = graph[cv][i].second;

      if (dist[nv] > dist[cv] + nw) {
        dist[nv] = dist[cv] + nw;
        pq.push({dist[cv] + nw, nv});

        // 2. store a previous vertex number going to the shortest path
        if (cv == start) {
          // 2-1. if the previous vertex number is "-", store the current vertex number
          res[start][nv] = nv;
        } else {
          res[start][nv] = cv;
        }
      }
    }
  }
}

void update_vertex_number(int standard) {
  set<int> first_vertexes;

  for (int i = 0; i < res[standard].size(); i++) {
    // if the next vertex number is standard vertex, skip this loop
    if (res[standard][i] == -1) continue;

    // if the next vertex number is same with i,
    //   insert the vertex number into a set
    //   and skip this loop
    if (res[standard][i] == i) {
      first_vertexes.insert(i);
      continue;
    }

    // found a target vertex number
    //   until the previous vertex number is same with standard vertex number
    int target = res[standard][i];

    while (first_vertexes.find(target) == first_vertexes.end()) {
      target = res[standard][target];

      if (target == res[standard][target]) {
        first_vertexes.insert(target);
      }
    }

    res[standard][i] = target;
  }
}