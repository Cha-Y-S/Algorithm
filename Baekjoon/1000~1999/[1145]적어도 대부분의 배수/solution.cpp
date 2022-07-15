#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<int> arr;
int res;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  arr = vector<int>(5, 0);
  res = 1;

  for (int i = 0; i < 5; i++) {
    cin >> arr[i];
  }

  while (true) {
    int cnt = 0;

    for (int i = 0; i < 5; i++) {
      if (res % arr[i] == 0) cnt++;
    }

    if (cnt >= 3) break;

    res++;
  }

  cout << res << endl;

  return 0;
}