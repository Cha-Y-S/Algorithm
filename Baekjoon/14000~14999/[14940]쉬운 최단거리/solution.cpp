#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<int, int> pii;

vector<vector<int>> matrix;
vector<vector<int>> visited;
vector<pii> dir;
pii start;
int N, M;

void bfs(pii s);
void print_matrix();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

  matrix = vector<vector<int>>(N, vector<int>(M));
  visited = vector<vector<int>>(N, vector<int>(M, -1));
  dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> matrix[i][j];

      if (matrix[i][j] == 2) start = {i, j};
    }
  }

  bfs(start);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (matrix[i][j] == 0) visited[i][j] = 0;
    }
  }

  print_matrix();

  return 0;
}

void bfs(pii s) {
  queue<pair<pii, int>> q;

  q.push({s, 0});
  visited[s.first][s.second] = 0;

  while (!q.empty()) {
    int cx = q.front().first.first;
    int cy = q.front().first.second;
    int cc = q.front().second;

    q.pop();

    for (int i = 0; i < dir.size(); i++) {
      int nx = cx + dir[i].first;
      int ny = cy + dir[i].second;

      if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

      if (visited[nx][ny] == -1 && matrix[nx][ny] == 1) {
        q.push({{nx, ny}, cc + 1});
        visited[nx][ny] = cc + 1;
      }
    }
  }
}

void print_matrix() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++)
      cout << visited[i][j] << " ";
    cout << endl;
  }
}