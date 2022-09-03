#include <iostream>

using namespace std;

#define endl "\n"
#define MAX(X, Y) (X < Y ? Y : X)
#define MIN(X, Y) (X < Y ? X : Y)
#define ROUND 4

int x1, y1, p1, q1;
int x2, y2, p2, q2;
int x_left, x_right, y_up, y_down;
int x_diff, y_diff;

void fast_io();
char classify_two_rectangle();

int main() {
  fast_io();

  for (int i = 0; i < ROUND; i++) {
    cin >> x1 >> y1 >> p1 >> q1 >> x2 >> y2 >> p2 >> q2;

    cout << classify_two_rectangle() << endl;
  }

  return 0;
}

void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

char classify_two_rectangle() {
  x_left = MAX(x1, x2);
  x_right = MIN(p1, p2);
  y_down = MAX(y1, y2);
  y_up = MIN(q1, q2);

  x_diff = x_right - x_left;
  y_diff = y_up - y_down;

  if (x_diff > 0 && y_diff > 0)
    return 'a';
  else if (x_diff == 0 && y_diff == 0)
    return 'c';
  else if (x_diff < 0 || y_diff < 0)
    return 'd';
  else
    return 'b';
}