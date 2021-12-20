#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<int> seq, cumulative;
int N, M, S, E;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;
  seq = vector<int>(N);
  cumulative = vector<int>(N);

  for (int i = 0; i < N; i++)
    cin >> seq[i];

  for (int i = 0; i < N; i++) {
    if (i == 0) {
      cumulative[i] = seq[i];
      continue;
    }
    cumulative[i] = seq[i] + cumulative[i - 1];
  }

  for (int i = 0; i < M; i++) {
    cin >> S >> E;

    if (S == 1)
      cout << cumulative[E - 1] << endl;
    else
      cout << cumulative[E - 1] - cumulative[S - 2] << endl;
  }

  return 0;
}