#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<int, bool> pib;

set<vector<int>> sequence_set;
vector<pib> visited;
vector<int> sequence;
int N, M;

void combination(int idx, int cnt);
void printSet();

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

  printSet();

  return 0;
}

void combination(int idx, int cnt) {
  if (cnt == M) {
    sequence_set.insert(sequence);
    return;
  }
  for (int i = idx; i < N; i++) {
    if (visited[i].second) continue;
    visited[i].second = true;
    sequence[cnt] = visited[i].first;
    combination(i + 1, cnt + 1);
    visited[i].second = false;
  }
}

void printSet() {
  for (vector<int> v : sequence_set) {
    for (int e : v)
      cout << e << " ";
    cout << endl;
  }
}