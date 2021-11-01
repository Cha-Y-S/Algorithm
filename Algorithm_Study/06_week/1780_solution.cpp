#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<vector<int>> paper;
vector<int> res;
int N;

void count_number(int r, int c, int n);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  paper = vector<vector<int>>(N, vector<int>(N));
  res = vector<int>(3, 0);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> paper[i][j];
    }
  }

  count_number(0, 0, N);

  for (int i = 0; i < 3; i++)
    cout << res[i] << endl;

  return 0;
}

void count_number(int r, int c, int n) {
  bool flag = true;
  if (n == 1) {
    res[paper[r][c] + 1]++;
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
    res[paper[r][c] + 1]++;
  else {
    for (int i = r; i < r + n; i += n / 3) {
      for (int j = c; j < c + n; j += n / 3)
        count_number(i, j, n / 3);
    }
  }
}