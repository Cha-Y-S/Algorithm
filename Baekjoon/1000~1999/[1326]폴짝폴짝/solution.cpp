#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<int, int> pii;

vector<int> step;
vector<bool> visited;
int N, A, B;

int bfs(int start, int finish);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  step = vector<int>(N + 1, 0);
  visited = vector<bool>(N + 1, false);

  for (int i = 1; i <= N; i++)
    cin >> step[i];

  cin >> A >> B;

  cout << bfs(A, B) << endl;

  return 0;
}

int bfs(int start, int finish) {
  queue<pii> q;

  q.push({0, start});
  visited[start] = true;

  while (!q.empty()) {
    int cnt = q.front().first;
    int cur = q.front().second;

    if (cur == finish) return cnt;

    q.pop();

    for (int i = 1; i <= N; i++) {
      int next = cur + (step[cur] * i);

      if (next > N) break;

      if (!visited[next]) {
        q.push({cnt + 1, next});
        visited[next] = true;
      }
    }

    for (int i = 1; i <= N; i++) {
      int next = cur - (step[cur] * i);

      if (next < 1) break;

      if (!visited[next]) {
        q.push({cnt + 1, next});
        visited[next] = true;
      }
    }
  }

  return -1;
}