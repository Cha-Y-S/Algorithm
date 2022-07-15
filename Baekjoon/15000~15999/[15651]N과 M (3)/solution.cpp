#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<int> sequence;
int N, M;

void permutation(int c);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

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
    sequence.push_back(i);
    permutation(c + 1);
    sequence.erase(sequence.end() - 1);
  }
}