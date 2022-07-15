#include <climits>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"
#define INF INT_MAX

vector<vector<int>> dist;
int N, M;

void print_distance();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

  dist = vector<vector<int>>(N, vector<int>(N, INF));

  for (int i = 0; i < N; i++)
    dist[i][i] = 0;

  for (int i = 0; i < M; i++) {
    int a, b, c;

    cin >> a >> b >> c;

    if (dist[a - 1][b - 1] > c) {
      dist[a - 1][b - 1] = c;
    }
  }

  for (int k = 0; k < N; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (dist[i][k] != INF && dist[k][j] != INF) {
          if (dist[i][j] >= dist[i][k] + dist[k][j])
            dist[i][j] = dist[i][k] + dist[k][j];
        }
      }
    }
  }
  print_distance();

  return 0;
}

void print_distance() {
  for (int i = 0; i < dist.size(); i++) {
    for (int j = 0; j < dist[i].size(); j++)
      cout << (dist[i][j] == INF ? 0 : dist[i][j]) << " ";
    cout << endl;
  }
}