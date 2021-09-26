#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<int> sequence;
vector<bool> visited;
int N, M;

void permutation(int c);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

  visited = vector<bool>(N + 1, false);

  permutation(0);

  return 0;
}

void permutation(int c) {
  if (c == M) {
    for (int i = 0; i < M; i++)
      cout << sequence[i] << " ";
    cout << endl;

    return;
  }

  for (int i = 1; i <= N; i++) {
    if (visited[i]) continue;
    visited[i] = true;
    sequence.push_back(i);
    permutation(c + 1);
    visited[i] = false;
    sequence.erase(sequence.end() - 1);
  }
}