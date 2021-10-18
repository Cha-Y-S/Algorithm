#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

vector<vector<int>> paper;
vector<vector<bool>> visited;
vector<pii> dir;
int N, M, cluster, area;

int bfs(int x, int y);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;
  paper = vector<vector<int>>(N, vector<int>(M));
  visited = vector<vector<bool>>(N, vector<bool>(M, false));
  dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  cluster = 0;
  area = 0;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++)
      cin >> paper[i][j];
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (!visited[i][j] && paper[i][j] == 1) {
        int temp = bfs(i, j);

        area = area < temp ? temp : area;
        cluster++;
      }
    }
  }

  cout << cluster << endl
       << area << endl;

  return 0;
}

int bfs(int x, int y) {
  queue<pii> q;
  int result = 0;

  q.push({x, y});
  visited[x][y] = true;

  while (!q.empty()) {
    int cx = q.front().first;
    int cy = q.front().second;

    q.pop();
    result++;

    for (int i = 0; i < dir.size(); i++) {
      int nx = cx + dir[i].first;
      int ny = cy + dir[i].second;

      if ((0 <= nx && nx < N) && (0 <= ny && ny < M)) {
        if (!visited[nx][ny] && paper[nx][ny] == 1) {
          q.push({nx, ny});
          visited[nx][ny] = true;
        }
      }
    }
  }

  return result;
}