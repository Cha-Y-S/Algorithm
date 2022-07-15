#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> graph;
vector<bool> visited;
int N, maximum, res;

int bfs(int start);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  graph = vector<int>(N + 1);
  maximum = 0;

  for (int i = 1; i <= N; i++) {
    cin >> graph[i];
  }

  for (int i = 1; i <= N; i++) {
    int tmp = bfs(i);

    if (maximum < tmp) {
      maximum = tmp;
      res = i;
    }
  }

  cout << res << endl;

  return 0;
}

int bfs(int start) {
  queue<int> q;
  visited = vector<bool>(N + 1, false);
  int result = 0;

  q.push(start);
  visited[start] = true;

  while (!q.empty()) {
    int cur = q.front();
    result++;

    q.pop();

    if (!visited[graph[cur]]) {
      q.push(graph[cur]);
      visited[graph[cur]] = true;
    }
  }

  return result;
}