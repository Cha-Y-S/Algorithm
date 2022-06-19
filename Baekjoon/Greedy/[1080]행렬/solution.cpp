#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define endl "\n"

typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef vector<vector<bool>> vvb;
typedef vector<bool> vb;

vvi matrix;
vvb diff;
string row;
int N, M, res;

void flip(int x, int y) {
  for (int i = x; i < x + 3; i++) {
    for (int j = y; j < y + 3; j++) {
      diff[i][j] = !diff[i][j];
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

  matrix = vvi(N, vi(M, 0));
  diff = vvb(N, vb(M, false));
  res = 0;

  for (int i = 0; i < N; i++) {
    cin >> row;

    for (int j = 0; j < M; j++) {
      matrix[i][j] = row[j] - '0';
    }
  }

  for (int i = 0; i < N; i++) {
    cin >> row;

    for (int j = 0; j < M; j++) {
      if (row[j] - '0' != matrix[i][j]) {
        diff[i][j] = true;
      }
    }
  }

  if (N < 3 || M < 3) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (diff[i][j]) {
          res = -1;
          break;
        }
      }
      if (res == -1) break;
    }
  } else {
    for (int i = 0; i <= N - 3; i++) {
      for (int j = 0; j <= M - 3; j++) {
        if (diff[i][j]) {
          flip(i, j);
          res++;
        }
      }
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (diff[i][j])
        res = -1;
    }
  }

  cout << res << endl;

  return 0;
}