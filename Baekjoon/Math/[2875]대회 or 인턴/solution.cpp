#include <iostream>

using namespace std;

#define endl "\n"

int N, M, K, res;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M >> K;

  res = 0;

  for (int i = 0; i <= K; i++) {
    int n = (N - i) / 2;
    int m = M - (K - i);
    int tmp = n > m ? m : n;

    res = res < tmp ? tmp : res;
  }

  cout << res << endl;

  return 0;
}