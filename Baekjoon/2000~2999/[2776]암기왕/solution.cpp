#include <iostream>
#include <map>

using namespace std;

#define endl "\n"

map<int, bool> note;
int T, N, M, num;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> T;

  while (T--) {
    cin >> N;

    for (int i = 0; i < N; i++) {
      cin >> num;

      note[num] = true;
    }

    cin >> M;

    for (int i = 0; i < M; i++) {
      cin >> num;

      cout << (note[num] ? 1 : 0) << endl;
    }

    note.clear();
  }

  return 0;
}