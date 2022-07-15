#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<int, int> pii;

vector<vector<char>> matrix;
vector<vector<int>> visited;
vector<pii> dir;
string row;
int N, M, start_x, start_y, finish_x, finish_y;
pii res;

pii bfs(int sx, int sy, int fx, int fy);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

  matrix = vector<vector<char>>(N, vector<char>(M));
  visited = vector<vector<int>>(N, vector<int>(M, -1));
  dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

  for (int i = 0; i < N; i++) {
    cin >> row;
    for (int j = 0; j < M; j++) {
      if (matrix[i][j] == 'n' && row[j] == '.') continue;
      matrix[i][j] = row[j];
      if (matrix[i][j] == 'S') {
        start_x = i;
        start_y = j;
      } else if (matrix[i][j] == 'F') {
        finish_x = i;
        finish_y = j;
      } else if (matrix[i][j] == 'g') {
        for (int k = 0; k < dir.size(); k++) {
          int nx = i + dir[k].first;
          int ny = j + dir[k].second;

          if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

          if (matrix[nx][ny] == 'S' || matrix[nx][ny] == 'g' || matrix[nx][ny] == 'F') continue;

          matrix[nx][ny] = 'n';
        }
      }
    }
  }

  res = bfs(start_x, start_y, finish_x, finish_y);

  cout << res.first << " " << res.second << endl;

  return 0;
}

pii bfs(int sx, int sy, int fx, int fy) {
  priority_queue<pair<pii, pii>, vector<pair<pii, pii>>, greater<pair<pii, pii>>> pq;
  pii result;

  pq.push({{0, 0}, {sx, sy}});
  visited[sx][sy] = 0;

  while (!pq.empty()) {
    int cgc = pq.top().first.first;
    int cnc = pq.top().first.second;
    int cx = pq.top().second.first;
    int cy = pq.top().second.second;

    if (cx == fx && cy == fy) {
      result = {cgc, cnc};
      break;
    }

    pq.pop();

    for (int i = 0; i < dir.size(); i++) {
      int nx = cx + dir[i].first;
      int ny = cy + dir[i].second;
      int ngc = cgc;
      int nnc = cnc;

      if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
      if (visited[nx][ny] != -1) continue;

      if (matrix[nx][ny] == 'g') ngc++;
      if (matrix[nx][ny] == 'n') nnc++;

      pq.push({{ngc, nnc}, {nx, ny}});
      visited[nx][ny] = visited[cx][cy] + 1;
    }
  }

  return result;
}