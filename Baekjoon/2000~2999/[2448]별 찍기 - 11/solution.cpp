#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> star;
int N;

void draw_star(int n, int x, int y);
void print_star();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  star = vector<vector<char>>(N, vector<char>(2 * N - 1, ' '));

  draw_star(N, 0, N - 1);

  print_star();

  return 0;
}

void draw_star(int n, int x, int y) {
  if (n == 3) {
    star[x][y] = '*';
    star[x + 1][y - 1] = '*';
    star[x + 1][y + 1] = '*';
    for (int i = 0; i < 5; i++)
      star[x + 2][y - i + 2] = '*';
    return;
  }

  draw_star(n / 2, x, y);
  draw_star(n / 2, x + n / 2, y - n / 2);
  draw_star(n / 2, x + n / 2, y + n / 2);
}

void print_star() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 2 * N - 1; j++) {
      cout << star[i][j];
    }
    cout << endl;
  }
}