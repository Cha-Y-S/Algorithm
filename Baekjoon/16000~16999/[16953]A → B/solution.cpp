#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<long long, int> pli;

int A, B, res;

int bfs(int start);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> A >> B;

  res = bfs(A);

  cout << (res == -1 ? res : res + 1) << endl;

  return 0;
}

int bfs(int start) {
  queue<pli> q;
  vector<bool> visited(B + 1, false);
  int result;

  q.push({start, 0});
  visited[start] = true;

  while (!q.empty()) {
    long long cur = q.front().first;
    int cnt = q.front().second;

    if (cur == B)
      return result = cnt;

    q.pop();

    if (cur * 2 <= (long long)B && !visited[cur * 2]) {
      q.push({cur * 2, cnt + 1});
      visited[cur * 2] = true;
    }

    if (cur * 10 + 1 <= (long long)B && !visited[cur * 10 + 1]) {
      q.push({cur * 10 + 1, cnt + 1});
      visited[cur * 10 + 1] = true;
    }
  }

  return result = -1;
}