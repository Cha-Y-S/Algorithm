#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<vector<int>> dist;
int N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  dist = vector<vector<int>>(N, vector<int>(N, 0));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++)
      cin >> dist[i][j];
  }

  for (int k = 0; k < N; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (dist[i][k] != 0 && dist[k][j] != 0)
          dist[i][j] = 1;
      }
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++)
      cout << dist[i][j] << " ";
    cout << endl;
  }

  return 0;
}