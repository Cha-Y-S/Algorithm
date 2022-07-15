#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl "\n"

vector<int> cnt, ladder;
int N, M, S, E;

void bfs(int start);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

  cnt = vector<int>(100, 0);
  ladder = vector<int>(100, -1);

  for (int i = 0; i < N + M; i++) {
    cin >> S >> E;

    ladder[S - 1] = E - 1;
  }

  bfs(0);

  cout << *(cnt.end() - 1) << endl;

  return 0;
}

void bfs(int start) {
  queue<int> q;

  q.push(start);

  while (!q.empty()) {
    int cur = q.front();

    q.pop();

    for (int i = 1; i <= 6; i++) {
      int next = cur + i;

      if (next >= 100) continue;

      if (ladder[next] != -1) next = ladder[next];

      if (cnt[next] == 0) {
        cnt[next] = cnt[cur] + 1;
        q.push(next);
      }
    }
  }
}