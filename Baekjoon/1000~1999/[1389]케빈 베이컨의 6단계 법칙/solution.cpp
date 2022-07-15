#include <climits>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<vector<int>> dist;
int N, M, res, cnt;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

  dist = vector<vector<int>>(N, vector<int>(M, 0));
  cnt = INT_MAX;

  for (int i = 0; i < M; i++) {
    int a, b;

    cin >> a >> b;

    dist[a - 1][b - 1] = 1;
    dist[b - 1][a - 1] = 1;
  }

  for (int k = 0; k < N; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (i == j) continue;
        if (dist[i][k] == 0 || dist[k][j] == 0) continue;
        if (dist[i][j] == 0)
          dist[i][j] = dist[i][k] + dist[k][j];
        else {
          dist[i][j] = dist[i][j] >= dist[i][k] + dist[k][j] ? dist[i][k] + dist[k][j] : dist[i][j];
        }
      }
    }
  }

  for (int i = 0; i < N; i++) {
    int temp = 0;
    for (int j = 0; j < N; j++)
      temp += dist[i][j];

    if (cnt > temp) {
      cnt = temp;
      res = i + 1;
    }
  }

  cout << res << endl;

  return 0;
}