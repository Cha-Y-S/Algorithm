#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<int, int> pii;

vector<string> matrix;
vector<pii> dirs;
int N, cnt;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  matrix = vector<string>(N, string(N, '.'));
  dirs = {{-1, 0}, {0, 1}, {0, -1}};

  cin >> matrix[0];

  for (int i = 0; i < N - 1; i++) {
    for (int j = 0; j < N; j++) {
      cnt = 0;
      for (int k = 0; k < dirs.size(); k++) {
        int nx = i + dirs[k].first;
        int ny = j + dirs[k].second;

        if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

        if (matrix[nx][ny] == '#') cnt++;
      }

      if (cnt % 2) matrix[i + 1][j] = '#';
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << matrix[i][j];
    }
    cout << endl;
  }

  return 0;
}