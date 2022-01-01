#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl "\n"
#define MAX 100'001

typedef pair<int, int> pii;

queue<pii> q;
vector<bool> visited;
int N, K, t_res, c_res;

void bfs();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> K;
  visited = vector<bool>(MAX, false);
  t_res = 0;
  c_res = 0;

  bfs();

  cout << t_res << endl
       << c_res << endl;

  return 0;
}

void bfs() {
  q.push({N, 0});
  visited[N] = true;

  while (!q.empty()) {
    int c_loc = q.front().first;
    int c_time = q.front().second;

    q.pop();

    visited[c_loc] = true;

    if (t_res && t_res == c_time && c_loc == K)
      c_res++;

    if (!t_res && c_loc == K) {
      t_res = c_time;
      c_res++;
    }

    if (c_loc + 1 < MAX && !visited[c_loc + 1])
      q.push({c_loc + 1, c_time + 1});
    if (c_loc - 1 >= 0 && !visited[c_loc - 1])
      q.push({c_loc - 1, c_time + 1});
    if (c_loc * 2 < MAX && !visited[c_loc * 2])
      q.push({c_loc * 2, c_time + 1});
  }
}