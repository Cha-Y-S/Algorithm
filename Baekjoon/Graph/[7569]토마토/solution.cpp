#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<pair<int, int>, int> ppiii;

vector<vector<vector<int>>> matrix;
vector<vector<vector<bool>>> visited;
vector<ppiii> tomato;
vector<ppiii> dir;
int N, M, H, z_cnt, answer;

void bfs();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> M >> N >> H;

  matrix = vector<vector<vector<int>>>(N, vector<vector<int>>(M, vector<int>(H)));
  visited = vector<vector<vector<bool>>>(N, vector<vector<bool>>(M, vector<bool>(H, false)));
  dir = {{{-1, 0}, 0}, {{0, 1}, 0}, {{1, 0}, 0}, {{0, -1}, 0}, {{0, 0}, 1}, {{0, 0}, -1}};
  z_cnt = 0;
  answer = 0;

  for (int k = 0; k < H; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        cin >> matrix[i][j][k];

        if (matrix[i][j][k] == 1)
          tomato.push_back({{i, j}, k});
        else if (matrix[i][j][k] == 0)
          z_cnt++;
      }
    }
  }

  if (z_cnt == 0) {
    cout << 0 << endl;
    return 0;
  }

  bfs();

  if (z_cnt > 0) {
    cout << -1 << endl;
  } else {
    cout << answer << endl;
  }

  return 0;
}

void bfs() {
  queue<ppiii> q;

  for (ppiii e : tomato) {
    int x = e.first.first;
    int y = e.first.second;
    int z = e.second;

    q.push(e);
    visited[x][y][z] = true;
  }

  while (!q.empty()) {
    int cx = q.front().first.first;
    int cy = q.front().first.second;
    int cz = q.front().second;

    q.pop();

    for (int i = 0; i < dir.size(); i++) {
      int nx = cx + dir[i].first.first;
      int ny = cy + dir[i].first.second;
      int nz = cz + dir[i].second;

      if ((0 <= nx && nx < N) && (0 <= ny && ny < M) && (0 <= nz && nz < H)) {
        if (!visited[nx][ny][nz] && matrix[nx][ny][nz] == 0) {
          matrix[nx][ny][nz] = matrix[cx][cy][cz] + 1;
          visited[nx][ny][nz] = true;
          q.push({{nx, ny}, nz});
          z_cnt--;
          answer = matrix[nx][ny][nz] - 1 > answer ? matrix[nx][ny][nz] - 1 : answer;
        }
      }
    }
  }
}