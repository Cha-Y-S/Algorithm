#include <climits>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"
#define INF INT_MAX

vector<vector<int>> dist;
int N, M, res;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

  dist = vector<vector<int>>(N, vector<int>(N, INF));

  for (int i = 0; i < N; i++)
    dist[i][i] = 0;

  for (int i = 0; i < M; i++) {
    int a, b;

    cin >> a >> b;

    dist[a - 1][b - 1] = 1;
  }

  for (int k = 0; k < N; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j])
          dist[i][j] = dist[i][k] + dist[k][j];
      }
    }
  }

  for (int i = 0; i < N; i++) {
    res = 0;
    for (int j = 0; j < N; j++) {
      if (dist[i][j] == INF && dist[j][i] == INF)
        res++;
    }
    cout << res << endl;
  }

  return 0;
}