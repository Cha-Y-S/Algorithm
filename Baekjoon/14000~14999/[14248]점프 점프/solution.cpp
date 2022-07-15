#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl "\n"

vector<int> bridge;
vector<bool> visited;
int N, S;

int bfs(int sv);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;
  bridge = vector<int>(N);
  visited = vector<bool>(N, false);

  for (int i = 0; i < N; i++)
    cin >> bridge[i];

  cin >> S;

  cout << bfs(S - 1) << endl;

  return 0;
}

int bfs(int sv) {
  queue<int> q;
  int result = 0;

  q.push(sv);
  visited[sv] = true;

  while (!q.empty()) {
    int cv = q.front();
    result++;

    q.pop();

    vector<int> nvs;

    nvs.push_back(cv + bridge[cv]);
    nvs.push_back(cv - bridge[cv]);

    for (int nv : nvs) {
      if (nv < 0 || nv >= N || visited[nv]) continue;
      q.push(nv);
      visited[nv] = true;
    }
  }

  return result;
}