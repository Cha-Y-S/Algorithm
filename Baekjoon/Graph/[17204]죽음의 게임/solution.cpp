#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl "\n"

vector<int> number;
vector<bool> visited;
int N, M;

int bfs(int v);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

  number = vector<int>(N);
  visited = vector<bool>(N, false);

  for (int i = 0; i < N; i++) {
    cin >> number[i];
  }

  cout << bfs(0) << endl;

  return 0;
}

int bfs(int v) {
  queue<int> q;
  int res = 1;

  q.push(number[v]);
  visited[v] = true;

  while (!q.empty()) {
    int cur = q.front();

    if (cur == M) {
      break;
    }

    q.pop();

    if (!visited[number[cur]]) {
      q.push(number[cur]);
      visited[number[cur]] = true;
      res++;
    } else
      res = -1;
  }

  return res;
}