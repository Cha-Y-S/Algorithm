#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<vector<char>> board;
int N;

void point_star(int n, int x, int y);
void print_star();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  board = vector<vector<char>>(pow(2, N), vector<char>(pow(2, N), ' '));

  point_star(N, 0, 0);
  print_star();

  return 0;
}

void point_star(int n, int x, int y) {
  if (n == 0) {
    board[x][y] = '*';
    return;
  }
  // pointing star at the upper left
  point_star(n - 1, x, y);
  // pointing star at the lower left
  point_star(n - 1, x + pow(2, n - 1), y);
  // pointing star at the upper right
  point_star(n - 1, x, y + pow(2, n - 1));
}

void print_star() {
  for (int i = 0; i < pow(2, N); i++) {
    // Do not print unecessary empty space on the end of line
    for (int j = 0; j < pow(2, N) - i; j++) {
      cout << board[i][j];
    }
    cout << endl;
  }
}