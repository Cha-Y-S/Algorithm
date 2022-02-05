#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<int, int> pii;

int C, S, T;

int bfs(int s, int t);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> C;

  for (; C > 0; C--) {
    cin >> S >> T;

    cout << bfs(S, T) << endl;
  }

  return 0;
}

int bfs(int s, int t) {
  priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
  int result = 0;

  pq.push({0, {s, t}});

  while (!pq.empty()) {
    int cc = pq.top().first;
    int cs = pq.top().second.first;
    int ct = pq.top().second.second;

    if (cs == ct) {
      result = cc;
      break;
    }

    pq.pop();

    if (cs * 2 <= ct + 3) pq.push({cc + 1, {cs * 2, ct + 3}});
    if (cs + 1 <= ct) pq.push({cc + 1, {cs + 1, ct}});
  }

  return result;
}