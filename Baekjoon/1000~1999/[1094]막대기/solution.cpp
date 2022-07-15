#include <iostream>

using namespace std;

#define endl "\n"

int X, res;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> X;

  res = 0;

  for (int i = 0; i <= 6; i++) {
    if (X & (1 << i)) res += 1;
  }

  cout << res << endl;

  return 0;
}