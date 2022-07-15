#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<int, bool> pib;

vector<pib> visited;
vector<int> sequence;
int N, M;

void combination(int idx, int cnt);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

  visited = vector<pib>(N, {0, false});
  sequence = vector<int>(M);

  for (int i = 0; i < N; i++)
    cin >> visited[i].first;

  sort(visited.begin(), visited.end());

  combination(0, 0);

  return 0;
}

void combination(int idx, int cnt) {
  if (cnt == M) {
    for (int i = 0; i < M; i++)
      cout << sequence[i] << " ";
    cout << endl;
    return;
  }
  for (int i = idx; i < N; i++) {
    visited[i].second = true;
    sequence[cnt] = visited[i].first;
    combination(i + 1, cnt + 1);
    visited[i].second = false;
  }
}