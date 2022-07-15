#include <iostream>

using namespace std;

#define endl "\n"

int day, car, res;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> day;

  res = 0;

  for (int i = 0; i < 5; i++) {
    cin >> car;

    res = car == day ? res + 1 : res;
  }

  cout << res << endl;

  return 0;
}