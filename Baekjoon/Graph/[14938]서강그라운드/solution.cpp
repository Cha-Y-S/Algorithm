#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"
#define INF 987654321

vector<vector<int>> dist;
vector<int> item;
int N, M, R, A, B, L, res;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M >> R;

  dist = vector<vector<int>>(N, vector<int>(N, INF));
  item = vector<int>(N);
  res = 0;

  for (int i = 0; i < N; i++)
    dist[i][i] = 0;

  for (int i = 0; i < N; i++)
    cin >> item[i];

  for (int i = 0; i < R; i++) {
    cin >> A >> B >> L;

    dist[A - 1][B - 1] = L;
    dist[B - 1][A - 1] = L;
  }

  for (int k = 0; k < N; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (dist[i][j] > dist[i][k] + dist[k][j])
          dist[i][j] = dist[i][k] + dist[k][j];
      }
    }
  }

  for (int i = 0; i < N; i++) {
    int max_item = 0;
    for (int j = 0; j < N; j++) {
      if (dist[i][j] > M) continue;

      max_item += item[j];
    }

    res = res > max_item ? res : max_item;
  }

  cout << res << endl;

  return 0;
}