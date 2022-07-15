#include <iostream>

using namespace std;

#define endl "\n"

int N, res;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  for (int i = 0; i < N; i++) {
    int tmp;

    cin >> tmp;

    res += tmp;
  }

  cout << res - (N - 1) << endl;

  return 0;
}