#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"
#define MOD 1'000'000'007

typedef vector<vector<long long>> matrix;

matrix fibo, res;
long long N;
int answer;

matrix operator*(const matrix &a, const matrix &b);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  fibo = matrix(2, vector<long long>(2, 1));
  res = matrix(2, vector<long long>(2, 0));

  fibo[1][1] = 0;

  for (int i = 0; i < res.size(); i++)
    res[i][i] = 1;

  cin >> N;

  N -= 1;

  while (N > 0) {
    if (N % 2 == 1)
      res = res * fibo;
    N /= 2;
    fibo = fibo * fibo;
  }

  answer = res[0][0];

  cout << answer << endl;

  return 0;
}

matrix operator*(const matrix &a, const matrix &b) {
  matrix result(2, vector<long long>(2, 0));

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        result[i][j] += ((a[i][k] % MOD) * (b[k][j] % MOD)) % MOD;
        result[i][j] %= MOD;
      }
    }
  }

  return result;
}