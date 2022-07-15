#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

typedef vector<vector<int>> matrix;

matrix m, res;
int N;
long long B;

matrix operator*(const matrix &a, const matrix &b);
void print_matrix();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> B;

  m = matrix(N, vector<int>(N));
  res = matrix(N, vector<int>(N));

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      cin >> m[i][j];

  for (int i = 0; i < N; i++)
    res[i][i] = 1;

  while (B > 0) {
    if (B % 2 == 1)
      res = res * m;
    B /= 2;
    m = m * m;
  }

  print_matrix();

  return 0;
}

matrix operator*(const matrix &a, const matrix &b) {
  matrix temp(N, vector<int>(N));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++) {
        temp[i][j] += a[i][k] * b[k][j];
      }
      temp[i][j] %= 1000;
    }
  }

  return temp;
}

void print_matrix() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++)
      cout << res[i][j] << " ";
    cout << endl;
  }
}