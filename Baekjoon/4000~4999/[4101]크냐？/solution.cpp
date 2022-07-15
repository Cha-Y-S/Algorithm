#include <iostream>

using namespace std;

#define endl "\n"

int N, M;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  while (true) {
    cin >> N >> M;

    if (N == 0 && M == 0) break;

    cout << (N > M ? "Yes" : "No") << endl;
  }

  return 0;
}