#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl "\n"

vector<vector<int>> matrix;
vector<vector<bool>> safe;
vector<vector<bool>> visited;
int n, high, safe_area;

void init(int rain);
void bfs(int x, int y);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  high = safe_area = -1;

  cin >> n;

  matrix = vector<vector<int>>(n, vector<int>(n));
  safe = vector<vector<bool>>(n, vector<bool>(n));
  visited = vector<vector<bool>>(n, vector<bool>(n));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> matrix[i][j];
      high = high < matrix[i][j] ? matrix[i][j] : high;
    }
  }

  for (int r = 0; r < high + 1; r++) {
    int area = 0;
    init(r);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (!visited[i][j] && safe[i][j]) {
          bfs(i, j);
          area++;
        }
      }
    }
    safe_area = safe_area < area ? area : safe_area;
  }

  cout << safe_area << endl;

  return 0;
}

void init(int r) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      visited[i][j] = false;
      if (matrix[i][j] <= r)
        safe[i][j] = false;
      else
        safe[i][j] = true;
    }
  }
}

void bfs(int x, int y) {
  vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  queue<pair<int, int>> q;

  visited[x][y] = true;
  q.push({x, y});

  while (!q.empty()) {
    int cx = q.front().first;
    int cy = q.front().second;

    q.pop();

    for (int i = 0; i < dir.size(); i++) {
      int nx = cx + dir[i].first;
      int ny = cy + dir[i].second;

      if ((0 <= nx && nx < n) && (0 <= ny && ny < n)) {
        if (!visited[nx][ny] && safe[nx][ny]) {
          q.push({nx, ny});
          visited[nx][ny] = true;
        }
      }
    }
  }
}