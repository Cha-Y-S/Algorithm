#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<vector<int>> paper;
vector<int> res;
int N;

void count_blue_white(int r, int c, int n);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  paper = vector<vector<int>>(N, vector<int>(N));
  res = vector<int>(2, 0);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++)
      cin >> paper[i][j];
  }

  count_blue_white(0, 0, N);

  cout << res[0] << endl
       << res[1] << endl;

  return 0;
}

void count_blue_white(int r, int c, int n) {
  bool flag = true;

  if (n == 1) {
    res[paper[r][c]]++;
    return;
  }

  for (int i = r; i < r + n; i++) {
    for (int j = c; j < c + n; j++) {
      if (paper[i][j] != paper[r][c]) {
        flag = false;
        break;
      }
    }
    if (!flag) break;
  }

  if (flag)
    res[paper[r][c]]++;
  else {
    count_blue_white(r, c, n / 2);
    count_blue_white(r, c + n / 2, n / 2);
    count_blue_white(r + n / 2, c, n / 2);
    count_blue_white(r + n / 2, c + n / 2, n / 2);
  }
}