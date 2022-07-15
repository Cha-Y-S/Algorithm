#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"
#define MOD 1'000'000

typedef vector<vector<long long>> matrix;

matrix m, res;
long long N;
int answer;

matrix operator*(const matrix &a, const matrix &b);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  m = matrix(2, vector<long long>(2, 1));
  res = matrix(2, vector<long long>(2, 0));

  m[1][1] = 0;

  for (int i = 0; i < 2; i++)
    res[i][i] = 1;

  N = N - 1;

  while (N > 0) {
    if (N % 2 == 1)
      res = res * m;
    N /= 2;
    m = m * m;
  }
  answer = res[0][0];

  cout << answer << endl;

  return 0;
}

matrix operator*(const matrix &a, const matrix &b) {
  matrix res(2, vector<long long>(2, 0));

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        res[i][j] += ((a[i][k] % MOD) * (b[k][j] % MOD)) % MOD;
        res[i][j] %= MOD;
      }
    }
  }

  return res;
}