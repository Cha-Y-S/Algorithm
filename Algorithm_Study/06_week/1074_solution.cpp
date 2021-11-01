#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int N, m_size, R, C, res;

void found_location(int r, int c, int n);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> R >> C;
  m_size = pow(2, N);
  res = 0;

  found_location(R, C, m_size);

  cout << res << endl;

  return 0;
}

void found_location(int r, int c, int n) {
  if (r == 0 && c == 0) {
    return;
  }
  int standard = pow((n / 2), 2);

  if ((n / 2) <= r) {
    res += standard * 2;
    r -= (n / 2);
  }
  if ((n / 2) <= c) {
    res += standard;
    c -= (n / 2);
  }

  found_location(r, c, n / 2);
}