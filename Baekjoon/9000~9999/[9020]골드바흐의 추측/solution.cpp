#include <climits>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t, n;

  vector<bool> prime_number(10001, true);

  prime_number[0] = false;
  prime_number[1] = false;

  for (int i = 2; i <= sqrt(10001) + 1; i++) {
    if (prime_number[i]) {
      for (int j = i + i; j < 10001; j += i) {
        prime_number[j] = false;
      }
    }
  }

  cin >> t;

  for (; t > 0; t--) {
    cin >> n;

    pair<int, int> partition = {0, INT_MAX};

    for (int i = 2; i <= n / 2; i++) {
      if (prime_number[i]) {
        int left = i;
        int right = n - i;
        if (!prime_number[right]) continue;

        if (abs(partition.second - partition.first) > abs(right - left)) {
          partition = {left, right};
        }
      }
    }

    cout << partition.first << " " << partition.second << endl;
  }

  return 0;
}