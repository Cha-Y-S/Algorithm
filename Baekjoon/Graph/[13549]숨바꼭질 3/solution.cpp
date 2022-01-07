#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl "\n"
#define MAX 100'001

typedef pair<int, int> pii;

vector<bool> visited;
int N, K;

int bfs(int start);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> K;
  visited = vector<bool>(MAX, false);

  cout << bfs(N) << endl;

  return 0;
}

int bfs(int start) {
  priority_queue<pii, vector<pii>, greater<pii>> pq;

  pq.push({0, start});
  visited[start] = true;

  while (!pq.empty()) {
    int cur_sec = pq.top().first;
    int cur_loc = pq.top().second;

    pq.pop();

    if (cur_loc == K)
      return cur_sec;

    if (cur_loc * 2 < MAX && !visited[cur_loc * 2]) {
      pq.push({cur_sec, cur_loc * 2});
      visited[cur_loc * 2] = true;
    }
    if (cur_loc + 1 <= K && !visited[cur_loc + 1]) {
      pq.push({cur_sec + 1, cur_loc + 1});
      visited[cur_loc + 1] = true;
    }
    if (cur_loc - 1 >= 0 && !visited[cur_loc - 1]) {
      pq.push({cur_sec + 1, cur_loc - 1});
      visited[cur_loc - 1] = true;
    }
  }
}