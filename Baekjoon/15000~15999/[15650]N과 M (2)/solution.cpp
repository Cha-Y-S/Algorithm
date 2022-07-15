#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<bool> visited;
vector<int> sequence;
int N, M;

void combination(int n, int c);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

  visited = vector<bool>(N + 1, false);
  sequence = vector<int>(M);

  combination(1, 0);

  return 0;
}

void combination(int n, int c) {
  if (c == M) {
    for (int i = 0; i < M; i++)
      cout << sequence[i] << " ";
    cout << endl;
    return;
  }
  for (int i = n; i <= N; i++) {
    if (visited[i]) continue;
    visited[i] = true;
    sequence[c] = i;
    combination(i + 1, c + 1);
    visited[i] = false;
  }
}