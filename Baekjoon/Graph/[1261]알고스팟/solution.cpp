#include <climits>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#define INF INT_MAX
#define endl "\n"

typedef pair<int, int> pii;

vector<vector<int>> matrix;
vector<vector<int>> dist;
int N, M;

void bfs(int x, int y);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

  matrix = vector<vector<int>>(M, vector<int>(N));
  dist = vector<vector<int>>(M, vector<int>(N, INF));

  for (int i = 0; i < M; i++) {
    string row;

    cin >> row;

    for (int j = 0; j < N; j++)
      matrix[i][j] = row[j] - '0';
  }

  bfs(0, 0);

  cout << dist[M - 1][N - 1] << endl;

  return 0;
}

void bfs(int x, int y) {
  queue<pii> q;
  vector<pii> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

  dist[x][y] = 0;
  q.push({x, y});

  while (!q.empty()) {
    int cx = q.front().first;
    int cy = q.front().second;

    q.pop();

    for (int i = 0; i < dir.size(); i++) {
      int nx = cx + dir[i].first;
      int ny = cy + dir[i].second;

      if ((0 <= nx && nx < M) && (0 <= ny && ny < N)) {
        if (matrix[nx][ny] == 1) {
          if (dist[nx][ny] > dist[cx][cy] + 1) {
            dist[nx][ny] = dist[cx][cy] + 1;
            q.push({nx, ny});
          }
        } else {
          if (dist[nx][ny] > dist[cx][cy]) {
            dist[nx][ny] = dist[cx][cy];
            q.push({nx, ny});
          }
        }
      }
    }
  }
}