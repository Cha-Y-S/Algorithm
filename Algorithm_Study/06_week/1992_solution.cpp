#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> image;
string res;
int N;

void archieve_image(int r, int c, int n);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  image = vector<vector<int>>(N, vector<int>(N));
  res = "";

  for (int i = 0; i < N; i++) {
    string input;

    cin >> input;

    for (int j = 0; j < input.size(); j++)
      image[i][j] = input[j] - '0';
  }

  archieve_image(0, 0, N);

  cout << res << endl;

  return 0;
}

void archieve_image(int r, int c, int n) {
  bool flag = true;
  int standard = image[r][c];

  if (n == 1) {
    if (standard == 0)
      res += '0';
    else
      res += '1';

    return;
  }

  // Check whether all pixel is same
  for (int i = r; i < r + n; i++) {
    for (int j = c; j < c + n; j++) {
      if (image[i][j] != standard) {
        flag = false;
        break;
      }
    }
    if (!flag) break;
  }

  if (flag) {
    if (standard == 0)
      res += '0';
    else
      res += '1';
  } else {
    res += '(';
    archieve_image(r, c, n / 2);
    archieve_image(r, c + n / 2, n / 2);
    archieve_image(r + n / 2, c, n / 2);
    archieve_image(r + n / 2, c + n / 2, n / 2);
    res += ')';
  }
}