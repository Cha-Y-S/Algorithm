#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl "\n"
#define MAX 100'000
#define MIN 0

typedef pair<int, int> pii;

vector<bool> visited;
queue<pii> q;
int A, B, N, M;

int bfs(int start, int finish);
void set_visited(int nv, int cc);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> A >> B >> N >> M;

  visited = vector<bool>(MAX + 1, false);

  cout << bfs(N, M) << endl;

  return 0;
}

int bfs(int start, int finish) {
  int result = 0;

  q.push({start, 0});
  visited[start] = true;

  while (!q.empty()) {
    int cv = q.front().first;
    int cc = q.front().second;

    if (cv == finish) {
      result = cc;
      break;
    }

    q.pop();

    set_visited(cv + 1, cc);

    set_visited(cv - 1, cc);

    set_visited(cv + A, cc);

    set_visited(cv - A, cc);

    set_visited(cv + B, cc);

    set_visited(cv - B, cc);

    set_visited(cv * A, cc);

    set_visited(cv * B, cc);
  }

  return result;
}

void set_visited(int nv, int cc) {
  if (nv > MAX || nv < MIN || visited[nv]) return;
  q.push({nv, cc + 1});
  visited[nv] = true;
}