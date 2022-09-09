#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl "\n"
#define vertex first
#define dist second
#define MAX(X, Y) (X > Y ? X : Y)

typedef pair<int, int> pii;

vector<vector<pii>> tree;
vector<bool> visited;
int N, A, B, W, endpoint_a, endpoint_b, res;

void fast_io();
pii get_endpoint(int start, int except = 0);

int main() {
  fast_io();

  cin >> N;

  tree = vector<vector<pii>>(N + 1);

  for (int i = 0; i < N - 1; i++) {
    cin >> A >> B >> W;

    tree[A].push_back({B, W});
    tree[B].push_back({A, W});
  }

  // Find out first endpoint configuring tree's diameter
  endpoint_a = get_endpoint(1).vertex;
  // Find out left endpoint configurting tree's diameter with endpoint_a
  endpoint_b = get_endpoint(endpoint_a).vertex;

  // Find out tree's diameter that A or B is excepted, And get maximum distance
  // out of 2 case
  res = MAX(get_endpoint(endpoint_a, endpoint_b).dist,
            get_endpoint(endpoint_b, endpoint_a).dist);

  cout << res << endl;

  return 0;
}

void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

pii get_endpoint(int start, int except) {
  visited = vector<bool>(N + 1, false);

  queue<pii> q;
  int max_dist = 0;
  int endpoint;

  visited[start] = true;
  // Excepted vertex will not be considered at this search.
  visited[except] = true;
  q.push({start, 0});

  while (!q.empty()) {
    int cur_vertex = q.front().vertex;
    int cur_dist = q.front().dist;

    q.pop();

    for (pii p : tree[cur_vertex]) {
      if (visited[p.vertex]) continue;

      int next_dist = cur_dist + p.dist;

      // Update vertex & distance info for finding out endpoint
      if (max_dist < next_dist) {
        endpoint = p.vertex;
        max_dist = next_dist;
      }

      visited[p.vertex] = true;
      q.push({p.vertex, p.dist + cur_dist});
    }
  }

  return {endpoint, max_dist};
}