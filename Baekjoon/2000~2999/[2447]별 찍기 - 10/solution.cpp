#include <iostream>

using namespace std;

#define endl "\n"

int N;

void draw_star(int i, int j, int n);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++)
      draw_star(i, j, N);
    cout << "\n";
  }

  return 0;
}

void draw_star(int i, int j, int n) {
  if ((i / n) % 3 == 1 && (j / n) % 3 == 1)
    cout << " ";
  else {
    if (n / 3 == 0)
      cout << "*";
    else
      draw_star(i, j, n / 3);
  }
}