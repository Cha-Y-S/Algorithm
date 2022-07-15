#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<bool> visited;
vector<int> sequence;
int N, M;

void combination(int idx, int cnt);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

  visited = vector<bool>(N + 1, false);
  sequence = vector<int>(M);

  combination(1, 0);

  return 0;
}

void combination(int idx, int cnt) {
  if (cnt == M) {
    for (int i = 0; i < M; i++)
      cout << sequence[i] << " ";
    cout << endl;
    return;
  }

  for (int i = idx; i <= N; i++) {
    sequence[cnt] = i;
    combination(i, cnt + 1);
  }
}