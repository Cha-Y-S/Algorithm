#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

void d(vector<bool> &is_self, int n);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<bool> is_self(10001, false);

  for (int i = 1; i < 10001; i++) {
    if (!is_self[i]) {
      cout << i << endl;
      d(is_self, i);
    }
  }

  return 0;
}

void d(vector<bool> &is_self, int n) {
  if (n >= 10001)
    return;
  else {
    int sum = n;

    while (n > 0) {
      sum += n % 10;
      n /= 10;
    }

    is_self[sum] = true;

    d(is_self, sum);
  }
}