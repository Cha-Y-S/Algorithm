#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl "\n"
#define INF 987'654'321

typedef pair<int, int> pii;

vector<vector<int>> graph;
vector<int> dist;
int N, M, A, B, res;

void bfs(int sv);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;
  graph = vector<vector<int>>(N);
  dist = vector<int>(N, INF);
  res = 0;

  for (int i = 0; i < M; i++) {
    cin >> A >> B;

    graph[A - 1].push_back(B - 1);
    graph[B - 1].push_back(A - 1);
  }

  bfs(0);

  for (int i = 1; i < dist.size(); i++) {
    res = dist[i] <= 2 ? res + 1 : res;
  }

  cout << res << endl;

  return 0;
}

void bfs(int sv) {
  priority_queue<pii, vector<pii>, greater<pii>> pq;

  pq.push({0, sv});
  dist[0] = 0;

  while (!pq.empty()) {
    int cw = pq.top().first;
    int cv = pq.top().second;

    pq.pop();

    for (int nv : graph[cv]) {
      if (dist[nv] > cw + 1) {
        pq.push({cw + 1, nv});
        dist[nv] = cw + 1;
      }
    }
  }
}