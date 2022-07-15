#include <iostream>
#include <queue>

using namespace std;

#define endl "\n"

typedef pair<int, int> pii;

priority_queue<int> pq;
queue<pii> q;
int T, N, M;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> T;

  for (; T > 0; T--) {
    cin >> N >> M;

    pq = priority_queue<int>();
    q = queue<pii>();

    int p, cnt;
    cnt = 0;
    for (int i = 0; i < N; i++) {
      cin >> p;

      q.push({p, i});
      pq.push(p);
    }

    while (!q.empty()) {
      int cp = q.front().first;
      int ci = q.front().second;

      q.pop();

      if (cp == pq.top()) {
        pq.pop();
        cnt++;
        if (ci == M) {
          cout << cnt << endl;
          break;
        }

      } else
        q.push({cp, ci});
    }
  }
}