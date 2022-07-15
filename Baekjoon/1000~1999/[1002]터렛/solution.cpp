#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int tCase;

  cin >> tCase;

  for (int i = 0; i < tCase; i++) {
    int x1, y1, r1, x2, y2, r2;

    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    double d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

    int answer;

    if (d == abs(r1 - r2) && d != 0)
      answer = 1;
    else if (d == r1 + r2)
      answer = 1;
    else if (d < abs(r1 - r2))
      answer = 0;
    else if (d < r1 + r2 && d > abs(r1 - r2))
      answer = 2;
    else if (d > r1 + r2)
      answer = 0;
    else if (d == 0 && r1 == r2)
      answer = -1;

    cout << answer << endl;
  }

  return 0;
}