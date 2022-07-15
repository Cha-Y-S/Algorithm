#include <algorithm>
#include <iostream>
#include <list>
#include <string>

using namespace std;

#define endl "\n"

list<string> enter;
string car;
int N, res;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;
  res = 0;

  for (int i = 0; i < N; i++) {
    cin >> car;

    enter.push_back(car);
  }

  for (int i = 0; i < N; i++) {
    cin >> car;

    list<string>::iterator it = find(enter.begin(), enter.end(), car);

    if (enter.begin() != it) {
      res++;
    }

    enter.erase(it);
  }

  cout << res << endl;

  return 0;
}