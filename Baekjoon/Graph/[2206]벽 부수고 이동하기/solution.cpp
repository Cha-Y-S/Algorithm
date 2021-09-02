#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#define endl "\n"

int bfs(vector<vector<int>> matrix, int n, int m);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;

  cin >> n >> m;

  vector<vector<int>> matrix(n, vector<int>(m, 0));

  for (int i = 0; i < n; i++) {
    string input;

    cin >> input;

    for (int j = 0; j < input.size(); j++)
      matrix[i][j] = input[j] - '0';
  }

  cout << bfs(matrix, n, m) << endl;

  return 0;
}

int bfs(vector<vector<int>> matrix, int n, int m) {
  int result = -1;
  vector<vector<vector<int>>> visited(n, vector<vector<int>>(m, vector<int>(2, 0)));
  queue<pair<pair<int, int>, int>> q;
  vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  pair<int, int> target = {n - 1, m - 1};

  q.push({{0, 0}, 1});
  visited[0][0][1] = 1;

  while (!q.empty()) {
    int cx = q.front().first.first;
    int cy = q.front().first.second;
    int block = q.front().second;

    q.pop();

    if (cx == target.first & cy == target.second) {
      result = visited[cx][cy][block];
      break;
    }

    for (int i = 0; i < dir.size(); i++) {
      int nx = cx + dir[i].first;
      int ny = cy + dir[i].second;

      if ((0 <= nx && nx < n) && (0 <= ny && ny < m)) {
        if (matrix[nx][ny] == 1 && block) {
          visited[nx][ny][block - 1] = visited[cx][cy][block] + 1;
          q.push({{nx, ny}, block - 1});
        } else if (matrix[nx][ny] == 0 && visited[nx][ny][block] == 0) {
          visited[nx][ny][block] = visited[cx][cy][block] + 1;
          q.push({{nx, ny}, block});
        }
      }
    }
  }

  return result;
}