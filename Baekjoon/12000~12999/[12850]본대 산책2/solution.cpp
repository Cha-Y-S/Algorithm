#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"
#define MOD 1000000007

typedef vector<vector<long long>> matrix;

matrix m, res;
int D;

matrix operator*(const matrix &a, const matrix &b);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> D;

  m = {
      {0, 1, 1, 0, 0, 0, 0, 0},
      {1, 0, 1, 1, 0, 0, 0, 0},
      {1, 1, 0, 1, 1, 0, 0, 0},
      {0, 1, 1, 0, 1, 1, 0, 0},
      {0, 0, 1, 1, 0, 1, 1, 0},
      {0, 0, 0, 1, 1, 0, 0, 1},
      {0, 0, 0, 0, 1, 0, 0, 1},
      {0, 0, 0, 0, 0, 1, 1, 0}};

  res = matrix(8, vector<long long>(8, 0));

  for (int i = 0; i < 8; i++)
    res[i][i] = 1;

  while (D > 0) {
    if (D % 2 == 1)
      res = res * m;
    D /= 2;
    m = m * m;
  }

  cout << res[0][0] << endl;

  return 0;
}

matrix operator*(const matrix &a, const matrix &b) {
  matrix temp(8, vector<long long>(8, 0));
  int size = a.size();

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      for (int k = 0; k < size; k++) {
        temp[i][j] += ((a[i][k] % MOD) * (b[k][j] % MOD)) % MOD;
        temp[i][j] %= MOD;
      }
    }
  }

  return temp;
}