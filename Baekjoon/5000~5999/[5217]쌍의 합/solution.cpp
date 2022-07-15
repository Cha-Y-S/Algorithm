#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<int, int> pii;

vector<pii> pairs;
int T, N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> T;

  while (T--) {
    cin >> N;

    for (int i = 1; i <= N / 2; i++) {
      int j = N - i;

      if (i != j) {
        pairs.push_back({i, j});
      }
    }

    cout << "Pairs for " << N << ": ";

    for (int i = 0; i < pairs.size(); i++) {
      cout << pairs[i].first << " " << pairs[i].second;

      if (i + 1 != pairs.size()) {
        cout << ", ";
      }
    }

    cout << endl;

    pairs.clear();
  }

  return 0;
}