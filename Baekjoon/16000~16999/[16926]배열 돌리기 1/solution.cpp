#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<vector<int>> matrix;
int N, M, R;

void print_matrix();
void rotate_matrix(int x1, int y1, int x2, int y2);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M >> R;

  matrix = vector<vector<int>>(N, vector<int>(M));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++)
      cin >> matrix[i][j];
  }

  for (int i = 0; i < R; i++)
    rotate_matrix(0, 0, N - 1, M - 1);

  print_matrix();

  return 0;
}

void print_matrix() {
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[i].size(); j++)
      cout << matrix[i][j] << " ";
    cout << endl;
  }
}

void rotate_matrix(int x1, int y1, int x2, int y2) {
  if (x1 >= x2 || y1 >= y2) return;

  int storage = matrix[x1][y1];

  for (int i = y1; i < y2; i++)
    matrix[x1][i] = matrix[x1][i + 1];

  for (int i = x1; i < x2; i++)
    matrix[i][y2] = matrix[i + 1][y2];

  for (int i = y2; i > y1; i--)
    matrix[x2][i] = matrix[x2][i - 1];

  for (int i = x2; i > x1; i--)
    matrix[i][y1] = matrix[i - 1][y1];

  matrix[x1 + 1][y1] = storage;

  rotate_matrix(x1 + 1, y1 + 1, x2 - 1, y2 - 1);
}