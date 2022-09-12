#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<int> coprime_count;
int N, C;

void fast_io();
void init_coprime_count();
int gcd(int a, int b);

int main() {
  fast_io();

  // Vector storing coprime count to N;
  coprime_count = vector<int>(1001);

  init_coprime_count();

  cin >> C;

  for (int i = 0; i < C; i++) {
    cin >> N;

    cout << coprime_count[N] << endl;
  }

  return 0;
}

void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

void init_coprime_count() {
  // <1, 0>, <0, 1>, <1, 1>
  coprime_count[1] = 3;

  for (int i = 2; i <= 1000; i++) {
    int cnt = 0;
    for (int j = 1; j <= i; j++) {
      if (gcd(i, j) == 1) {
        // <i, j> and <j, i>
        cnt += 2;
      }
    }
    coprime_count[i] = cnt + coprime_count[i - 1];
  }
}

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}