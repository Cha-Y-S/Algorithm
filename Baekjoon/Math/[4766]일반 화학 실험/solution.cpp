#include <iostream>

using namespace std;

#define endl "\n"

double last, cur;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> last;
  cur = 0;

  cout << fixed;
  cout.precision(2);

  while (true) {
    cin >> cur;

    if (cur == 999) break;

    cout << cur - last << endl;

    last = cur;
  }

  return 0;
}