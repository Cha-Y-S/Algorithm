#include <iostream>

using namespace std;

#define endl "\n"

int A, B, C;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> A >> B >> C;

  if (B - A > C - B) {
    cout << B - A - 1 << endl;
  } else {
    cout << C - B - 1 << endl;
  }

  return 0;
}