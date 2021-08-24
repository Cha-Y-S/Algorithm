#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n";
#define MAX 1000001

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;

  vector<bool> prime_number(MAX, true);
  prime_number[0] = prime_number[1] = false;

  for (int i = 2; i <= sqrt(MAX) + 1; i++) {
    if (prime_number[i]) {
      for (int j = i + i; j < MAX; j += i)
        prime_number[j] = false;
    }
  }

  while (true) {
    cin >> n;

    if (!n) break;

    pair<int, int> operand = {1, 0};

    for (int j = 3; j <= n / 2; j += 2) {
      if (prime_number[j] && prime_number[n - j]) {
        operand = {j, n - j};
        break;
      }
    }

    if (operand.first == 1 && !operand.second) {
      cout << "Goldbach's conjecture is wrong.\n";
    } else {
      cout << n << " = " << operand.first << " + " << operand.second << "\n";
    }
  }

  return 0;
}