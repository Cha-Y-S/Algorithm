#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<int, int> pii;

vector<vector<char>> matrix;
vector<vector<bool>> visited;
vector<pii> dir;
vector<int> white;
vector<int> blue;
string row;
int N, M, w_res, b_res;

int bfs(int sx, int sy, char color);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

  matrix = vector<vector<char>>(M, vector<char>(N, ' '));
  visited = vector<vector<bool>>(M, vector<bool>(N, false));
  dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  w_res = b_res = 0;

  for (int i = 0; i < M; i++) {
    cin >> row;

    for (int j = 0; j < N; j++)
      matrix[i][j] = row[j];
  }

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      if (!visited[i][j]) {
        if (matrix[i][j] == 'W')
          white.push_back(bfs(i, j, 'W'));
        else
          blue.push_back(bfs(i, j, 'B'));
      }
    }
  }

  for (int i = 0; i < white.size(); i++)
    w_res += white[i] * white[i];

  for (int i = 0; i < blue.size(); i++)
    b_res += blue[i] * blue[i];

  cout << w_res << " " << b_res << endl;

  return 0;
}

int bfs(int sx, int sy, char color) {
  queue<pii> q;
  int cnt = 0;

  q.push({sx, sy});
  visited[sx][sy] = true;

  while (!q.empty()) {
    int cx = q.front().first;
    int cy = q.front().second;

    cnt++;
    q.pop();

    for (int i = 0; i < dir.size(); i++) {
      int nx = cx + dir[i].first;
      int ny = cy + dir[i].second;

      if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;

      if (!visited[nx][ny] && matrix[nx][ny] == color) {
        q.push({nx, ny});
        visited[nx][ny] = true;
      }
    }
  }

  return cnt;
}