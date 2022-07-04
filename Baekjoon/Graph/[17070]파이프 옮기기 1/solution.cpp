#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

#define endl "\n"

vector<vector<int>> matrix;
vector<pii> dirs;
int N, res;

void dfs(int x, int y, int p);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  matrix = vector<vector<int>>(N, vector<int>(N));
  dirs = {{0, 1}, {1, 0}, {1, 1}};

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> matrix[i][j];
    }
  }

  dfs(0, 1, 0);

  cout << res << endl;

  return 0;
}

void dfs(int x, int y, int p) {
  if (x == N - 1 && y == N - 1) {
    res++;
    return;
  }

  for (int i = 0; i < 3; i++) {
    if ((i == 0 && p == 1) || (i == 1 && p == 0)) {
      continue;
    }

    int nx = x + dirs[i].first;
    int ny = y + dirs[i].second;

    if (nx >= N || ny >= N || matrix[nx][ny] == 1) {
      continue;
    }

    if (i == 2 && (matrix[x][y + 1] == 1 || matrix[x + 1][y] == 1)) {
      continue;
    }

    dfs(nx, ny, i);
  }
}