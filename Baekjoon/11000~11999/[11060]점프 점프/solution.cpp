#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<int, int> pii;

vector<int> miro;
vector<bool> visited;
int N;

int bfs();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  miro = vector<int>(N);
  visited = vector<bool>(N, false);

  for (int i = 0; i < N; i++)
    cin >> miro[i];

  cout << bfs() << endl;

  return 0;
}

int bfs() {
  queue<pii> q;
  int result = -1;

  q.push({0, 0});
  visited[0] = true;

  while (!q.empty()) {
    int cc = q.front().first;
    int cv = q.front().second;

    if (cv == N - 1) {
      result = cc;
      break;
    }

    q.pop();

    for (int i = miro[cv]; i > 0; i--) {
      int nv = cv + i;

      if (nv >= N) continue;

      if (!visited[nv]) {
        q.push({cc + 1, nv});
        visited[nv] = true;
      }
    }
  }

  return result;
}